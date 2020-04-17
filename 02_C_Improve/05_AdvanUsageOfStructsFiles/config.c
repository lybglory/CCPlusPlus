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
int IsValidLine(char *buffer) {
	//#Ӣ�۵�����
	//heroName:���ѫ�
	//û��':'��ʾ������Ч����,�ո�ͷҲ������Ч����
	//�ַ����ң��ɹ����ص�һ�γ��ֵĵ�ַ;ʧ�ܷ���null

	if (buffer[0]=='\n'||strchr(buffer,':')==NULL) {
		return 0;		//��ʾ������Ч��
	}else { 
		return 1;		//��Ч��
	}
}

extern void Filesanalysis(const *filePath,int lines, struct config **cfg_p) {
	struct config *tmpCfg = (struct config*)malloc(sizeof(struct config)*lines);
	if (tmpCfg==NULL) {
		perror("config pinter is null!");
		return;
	}
	memset(tmpCfg,0, sizeof(struct config)*lines);
	FILE *fp = fopen(filePath, "r");
	if (fp == NULL) {
		perror("open error!");
		return;
	}
	char buffer[100] = { 0 };
	int i = 0;
	while (fgets(buffer,sizeof(buffer),fp)!=NULL) {
		if (IsValidLine(buffer)) {
			memset(tmpCfg[i].key,0,20);
			memset(tmpCfg[i].value, 0, 50);
			//heroName:���ѫ�
			char *pos = strchr(buffer, ':');
			//printf("buffer=%s;pos=%s\n",buffer,pos);
			//����������Ԫ�ص��׵�ַ
			strncpy(tmpCfg[i].key,buffer,pos-buffer);
			strncpy(tmpCfg[i].value, pos+1,strlen(pos+1)-1);
			//printf("config[%d].key=%s\n",i, config[i].key);
			//printf("config[%d].value=%s\n", i, config[i].value);
			i++;
		}
		memset(buffer,0, sizeof(buffer));
	}//while_end
	*cfg_p = tmpCfg;
	fclose(fp);
}

extern char *GetKeyValue(char *key,struct config *cfg,int lines) {
	for (size_t i = 0; i < lines; i++)
	{
		if (strcmp(key,cfg[i].key)==0) {
			return cfg[i].value;
		}
	}
}

extern void FreeStruHeap(struct config *config) {
	if (config!=NULL) {
		free(config);
		config = NULL;
	}
}