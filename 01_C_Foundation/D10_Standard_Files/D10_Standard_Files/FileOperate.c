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
	while (!feof(fp)) {
		printf("str[n]=%c\n",str[n]);
		char temp =fputc(str[n], fp);
		n++;
	}
	fclose(fp);
}
void main() {
	//FilesOpen();
	FileInput();
}