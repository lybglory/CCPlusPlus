#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
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
	int n = 0;
	printf("Please enter the text to write:\n");
	while (1)
	{
		
		fgets(input,sizeof(input), stdin);
		if (strncmp(input,"quit",strlen("quit"))==0) {
			printf("==quit!==");
			break;
		}
		
		while (input[n]!=0) {
			fputc(input[n++],fp);
		}
	}
	fclose(fp);
}

void main() {
	//FilesOpen();
	//FileInput();lianxi
	//FileReadChar();
	FilePractice();
}