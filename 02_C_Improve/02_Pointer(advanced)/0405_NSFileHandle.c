#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int WirteAndGetLine(FILE *fp,int lines) {
	fp = fopen("poetry.txt", "w");
	if (fp==NULL) {
		perror("Open error!");
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
	fclose(fp);
	return lines;
}

void WriteArray(FILE *fp,char **array,int len) {

	fp = fopen("poetry.txt", "r");
	if (fp==NULL) {
		perror("Open error!");
	}

	int index = 0;
	while (fgets(*array,len, fp))
	{
		printf("*array=%s", *array[index]);
		int currentLineChars = strlen(array[index])+1;
		int lastChar = strlen(array[index]) - 1;
		//字符串最后字符改为 \0
		array[lastChar] = '\0';

		int lineSize = sizeof(char) * currentLineChars;
		////heap area 每一行开辟一个堆区
		char *lineStr = malloc(lineSize);
		memset(lineStr,0, lineSize);
		//strcpy(lineStr, temp);
		//array[index] = currentLine;
		//printf("temp=%s\n",index, temp);
		index++;
	}
	fclose(fp);

}

//
void PrintfArr(char **pArray,int lines) {
	for (size_t i = 0; i < lines; i++)
	{
		printf("%d line:%s", i, &pArray[i]);
	}
}
void main() {
	FILE *fp=NULL;
	int lines = 0;
	lines=WirteAndGetLine(fp,lines);
	printf("\nlines=%d\n",lines);
	//
	char *toWriteArr = (char *)malloc(sizeof(char)*lines);
	memset(toWriteArr,0, sizeof(char) * lines);
	WriteArray(fp, &toWriteArr,lines);
	PrintfArr(toWriteArr,lines);

}