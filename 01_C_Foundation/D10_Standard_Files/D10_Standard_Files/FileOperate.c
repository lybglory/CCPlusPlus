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
void main() {
	//FilesOpen();
	//FileInput();
	FileReadChar();
}