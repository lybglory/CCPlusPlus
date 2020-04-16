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