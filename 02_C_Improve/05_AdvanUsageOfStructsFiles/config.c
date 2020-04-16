#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
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