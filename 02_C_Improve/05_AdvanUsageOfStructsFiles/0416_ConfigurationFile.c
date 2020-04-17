#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
void main() {
	int lines=GetFileLine("config.txt");
	printf("lines=%d\n",lines);
	struct ConfigInfo *cfgInfo = NULL;
	//Filesanalysis函数改变main函数的值，需要传入高级指针给它
	Filesanalysis("config.txt", lines,&cfgInfo );
	//char *temp = "heroName:朱友珪";
	//char* pos1 = strstr(temp,":");
	//char *pos2=strstr(temp,"朱");

	//printf("strlen(temp)=%d,冒号位置=%d；算出朱的pos=%d; 实际朱的位置=%d\n",strlen(temp),pos1-temp, pos1 - temp +1,pos2-temp);
	//printf("%s\n",pos1+1);
}