#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **HeapArea(int lines) {
	if (lines < 0) {
		return NULL;
	}
	char text[] = "山寺桃花始盛开，";
	char **temp = (char**)malloc(sizeof(char*)*lines);
	if (temp ==NULL) {
		return NULL;
	}
	for (size_t i = 0; i < lines; i++)
	{
		temp[i] = (char *)malloc(strlen(text)+1);
		switch (i)
		{
		case 0:
			strcpy(temp[i], "人间四月芳菲尽，");
			break;
		case 1:
			strcpy(temp[i], "山寺桃花始盛开。");
			break;
		case 2:
			strcpy(temp[i], "长恨春归无觅处，");
			break;
		case 3:
			strcpy(temp[i], "不知转入此中来。");
			break;
		}
	}
	return temp;
}

void PrintfSecPoint(char **p,int length) {
	for (size_t i = 0; i < length; i++)
	{
		printf("%s\n",p[i]);
	}
}
void FreeHeapArea(char **p,int len) {
	if (p==NULL) {
		return;
	}
	for (size_t i = 0; i < len; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
}
void main() {
	int lines = 4;
	char **p=HeapArea(lines);
	PrintfSecPoint(p,lines);
	FreeHeapArea(p, lines);
}