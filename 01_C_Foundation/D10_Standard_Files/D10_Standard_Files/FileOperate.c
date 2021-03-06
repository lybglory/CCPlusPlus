#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//FILE *fopen(const char * filename, const char * mode);
void FilesOpen() {
	//FILE *fp = fopen("note.txt","r");
	//FILE *fp = fopen("../note.txt","r");
	FILE *fp = fopen("E:/note.txt", "r");
	if (fp==NULL) {
		perror("file read error!\n");
		return;
	}
	else{
		perror("file read success!\n");
	}

}

void FileInput() {
	char str[] = "TodayIs20200317";
	FILE *fp = fopen("note.txt", "w");
	int n = 0;
	while (str[n]!=0) {
		fputc(str[n], fp);
		printf("%c", str[n]);
		n++;
	}
	fclose(fp);
}
void FileReadChar() {
	FILE *fp = fopen("note.txt", "r");
	char chr = 0;
	//feof返回值=0是，表示没有到文件结尾
	while (feof(fp)==0) {
		chr = fgetc(fp);
		printf("%c", chr);
	}
	fclose(fp);
}
//键盘不停的获取输入 将这些获取到的字符串 
//用fputc写入文件, 直到键盘输入“:quit”退出写入
void FilePractice() {
	//打开文件
	FILE *fp = fopen("IO.txt","w");
	if (fp==NULL) {
		perror("read error!");
		return;
	}

	char input[100];
	
	printf("Please enter the text to write:\n");
	while (1)
	{
		
		fgets(input,sizeof(input), stdin);
		if (strncmp(input,"quit",strlen("quit"))==0) {
			printf("==quit!==");
			break;
		}
		int n = 0;
		while (input[n]!=0) {
			fputc(input[n++],fp);
		}
	}
	fclose(fp);
}

void FileFputs() {
	printf("fputs\n");
	char *p_chArr[] = { "落霞与孤鹜齐飞，\n","秋水共长天一色。\n","渔舟唱晚，响穷彭蠡之滨；\n","雁阵惊寒，声断衡阳之浦\n" };
	//打开文件
	FILE *fp = fopen("poetry.txt", "w");
	int i = 0;
	int len = sizeof(p_chArr) / sizeof(p_chArr[0]);
	//操作文件
	while (i<len) {
		fputs(p_chArr[i], fp);
		i++;
	}
	//关闭文件
	fclose(fp);
}

void FileFgets() {
	FILE *fp = fopen("poetry.txt", "r");
	if (fp==NULL) {
		perror("read error!");
		return;
	}

	char rdBuffer[50]="";
	while (fgets(rdBuffer, sizeof(rdBuffer), fp)){
		printf("%s",rdBuffer);
	}
	fclose(fp);
}

void FileWorksheet() {
	FILE *fp = fopen("Worksheet.txt","w");
	if (fp==NULL) {
		perror("read error!");
		return;
	}
	//100以内的 3+19=

	srand(time(NULL));
	int n1,n2,index = 0;
	char operator[4] = { '+','-','*','/' };
	char arithmetic[10];
	//50道
	for (size_t i = 0; i < 50; i++){
		n1 = rand() % 100;
		n2 = rand() % 100;
		index = rand() % 100 % 4;
		sprintf(arithmetic, "%d%c%d=\n", n1, operator[index], n2);
		printf("%s", arithmetic);
		fputs(arithmetic, fp);
	}
	
	fclose(fp);
}

void Solve() {
	//打开文件：只读
	FILE *r_fp = fopen("Worksheet.txt", "r");
	if (r_fp==NULL) {
		perror("read error!");
		return;
	}

	FILE *w_fp= fopen("Solve.txt", "w");
	if (w_fp == NULL) {
		perror("read error!");
		return;
	}

	char chrs[20];
	int n1, n2, index= 0;
	float result = 0;
	char operator[4] = { '+','-','*','/' };
	while (fgets(chrs,sizeof(chrs),r_fp))
	{
		printf("%s",chrs);
		//解包
		sscanf(chrs, "%d%c%d=\n", &n1, &operator[index], &n2);
		switch (operator[index])
		{
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case '*':
			result = n1 * n2;
			break;
		case '/':
			result = n1 / n2;
			break;
		}
		//进行组包：
		char answers[20];
		sprintf(answers, "%d%c%d=%0.1lf\n", n1, operator[index], n2,result);
		//计算结果写入新文件
		fputs(answers, w_fp);
	}

	fclose(r_fp);
	fclose(w_fp);
}
void main() {
	//FilesOpen();
	//FileInput();lianxi
	//FileReadChar();
	//FilePractice();
	//FileFputs();
	//FileFgets();
	//FileWorksheet();
	Solve();
}