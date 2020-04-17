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
	}
	int lines = 0;
	char buffer[200] = {0};

	while (fgets(buffer,sizeof(buffer),fp_read)!=NULL){
		
		if (IsValidLine(buffer)) {
			lines++;
		}
		
	}
	return lines;
}
//
extern int IsValidLine(char *buffer) {
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

extern void Filesanalysis(const *filePath,int lines, struct ConfigInfo **struConfig) {
	struct ConfigInfo *config = (struct ConfigInfo*)malloc(sizeof(struct ConfigInfo));
	if (config==NULL) {
		perror("config pinter is null!");
		return;
	}
	memset(config,0, sizeof(struct ConfigInfo));
	FILE *fp = fopen(filePath, "r");
	if (fp == NULL) {
		perror("open error!");
		return;
	}
	char buffer[100] = { 0 };
	int i = 0;
	while (fgets(buffer,sizeof(buffer),fp)!=NULL) {
		if (IsValidLine(buffer)) {
			//heroName:���ѫ�
			char *pos = strchr(buffer, ':');
			//����������Ԫ�ص��׵�ַ
			strncpy(config[i].key,buffer,pos-buffer);
			strncpy(config[i].value, pos+1,strlen(pos+1)-1);
			printf("config[%d].key=%s\n",i, config[i].key);
			printf("config[%d].value=%s\n", i, config[i].value);
			i++;
		}

	}//while_end
	*struConfig = config;

}