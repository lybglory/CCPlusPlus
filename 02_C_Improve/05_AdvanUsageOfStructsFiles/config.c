#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
//
extern int GetFileLine(const char *path) {
	FILE *fp_read = fopen(path,"r");
	if(fp_read==NULL){
		perror("open error");
		return -1;
	}
	int lines = 0;
	char buffer[200] = {0};

	while (fgets(buffer,sizeof(buffer),fp_read)!=NULL){
		
		if (IsValidLine(buffer)) {
			lines++;
		}
		
	}
	fclose(fp_read);
	return lines;
}
//
extern int IsValidLine(char *buffer) {
	//#英雄的姓名
	//heroName:朱友珪
	//没有':'表示不是有效数据,空格开头也不是有效数据
	//字符查找，成功返回第一次出现的地址;失败返回null

	if (buffer[0]=='\n'||strchr(buffer,':')==NULL) {
		return 0;		//表示不是有效行
	}else { 
		return 1;		//有效行
	}
}

extern void Filesanalysis(const *filePath,int lines, struct ConfigInfo **struConfig) {
	struct ConfigInfo *tempCfg = (struct ConfigInfo*)malloc(sizeof(struct ConfigInfo)*lines);
	if (tempCfg==NULL) {
		perror("config pinter is null!");
		return;
	}
	memset(tempCfg,0, sizeof(struct ConfigInfo)*lines);
	FILE *fp = fopen(filePath, "r");
	if (fp == NULL) {
		perror("open error!");
		return;
	}
	char buffer[100] = { 0 };
	int i = 0;
	while (fgets(buffer,sizeof(buffer),fp)!=NULL) {
		if (IsValidLine(buffer)) {
			memset(tempCfg[i].key,0,20);
			memset(tempCfg[i].value, 0, 50);
			//heroName:朱友珪
			char *pos = strchr(buffer, ':');
			//printf("buffer=%s;pos=%s\n",buffer,pos);
			//数组名代表元素的首地址
			strncpy(tempCfg[i].key,buffer,pos-buffer);
			strncpy(tempCfg[i].value, pos+1,strlen(pos+1)-1);
			//printf("config[%d].key=%s\n",i, config[i].key);
			//printf("config[%d].value=%s\n", i, config[i].value);
			i++;
		}
		memset(buffer,0, sizeof(buffer));
	}//while_end
	*struConfig = tempCfg;
	fclose(fp);
}

extern char *GetKeyValue(char *key,struct ConfigInfo *cfg,int lines) {
	for (size_t i = 0; i < lines; i++)
	{
		if (strcmp(key,cfg[i].key)==0) {
			return cfg[i].value;
		}
	}
}

extern void FreeStruHeap(struct ConfigInfo *config) {
	if (config!=NULL) {
		free(config);
		config = NULL;
	}
}