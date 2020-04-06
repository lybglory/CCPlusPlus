#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int WirteAndGetLine(FILE *fp,int lines) {
	fp = fopen("poetry.txt", "w");
	if (fp == NULL) {
		perror("Open error!");
		return;
	}
	char *buff[] = {"清明时节雨纷纷，\n路上行人欲断魂。\n借问酒家何处有？\n牧童遥指杏花村。" };
	int counts=sizeof(buff)/sizeof(buff[0]); //lines=1
	int i = 0;
	while (i < counts) {
		fputs(buff[i], fp);
		i++;
	}
	rewind(fp);						//Reset file stream
	fp = fopen("poetry.txt", "r");
	char chr[200] = "";
	while (fgets(chr, sizeof(chr), fp))
	{
		printf("chr=%s", chr);
		lines++;	//get line counts
	}
	return lines;
}

void WriteArray(FILE *fp,char **array,int len) {
	if (fp==NULL||array == NULL||len <= 0) {
		printf("fp||array||len is null !\n");
		return;
	}

	int index = 0;
	char buffer[200] = {0};//字符串数组，要搞清楚。
	while (fgets(buffer,sizeof(buffer), fp)!=NULL)
	{
		printf("buffer=%s", buffer);
		int currentLineChars = strlen(buffer)+1;
		printf("%d\n",currentLineChars);
		int lastChar = strlen(buffer) - 1;
		//字符串最后字符改为 \0
		buffer[lastChar] = '\0';

		int lineSize = sizeof(char) * currentLineChars;
		//heap area 每一行开辟一个堆区
		char *lineStr = malloc(lineSize);
		strcpy(lineStr, buffer);
		array[index++] = lineStr;
		memset(buffer,0, sizeof(buffer));
		//printf("*array=%s\n", *array);
	}
}//func_end

//
void PrintfArr(char **pArray,int lines) {
	for (size_t i = 0; i < lines; i++)
	{
		printf("%d line:%s\n", i, pArray[i]);
	}
}

void freeSpace(char** pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			printf("%s被释放了\n", pArray[i]);
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
	free(pArray);
	pArray = NULL;

}

void main() {
	FILE * fp = fopen("poetry.txt", "r");
	if (fp == NULL) {
		perror("Open error!");
		return;
	}
	int lines = 0;
	lines = WirteAndGetLine(fp, lines);
	printf("\nA-Row=%d\n", lines);
	char **toWriteArr = (char *)malloc(sizeof(char)*lines);
	//memset(toWriteArr,0, sizeof(char) * lines);
	WriteArray(fp, toWriteArr,lines);
	PrintfArr(toWriteArr,lines);
	freeSpace(toWriteArr, lines);
	toWriteArr = NULL;
	fclose(fp);
	
}