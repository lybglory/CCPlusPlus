#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
void main() {
	int lines=GetFileLine("config.txt");
	printf("lines=%d\n",lines);
	struct ConfigInfo *cfgInfo = NULL;
	//Filesanalysis�����ı�main������ֵ����Ҫ����߼�ָ�����
	Filesanalysis("config.txt", lines,&cfgInfo );
	//char *temp = "heroName:���ѫ�";
	//char* pos1 = strstr(temp,":");
	//char *pos2=strstr(temp,"��");

	//printf("strlen(temp)=%d,ð��λ��=%d��������pos=%d; ʵ�����λ��=%d\n",strlen(temp),pos1-temp, pos1 - temp +1,pos2-temp);
	//printf("%s\n",pos1+1);
}