#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	//feof����ֵ=0�ǣ���ʾû�е��ļ���β
	while (feof(fp)==0) {
		chr = fgetc(fp);
		printf("%c", chr);
	}
	fclose(fp);
}
//���̲�ͣ�Ļ�ȡ���� ����Щ��ȡ�����ַ��� 
//��fputcд���ļ�, ֱ���������롰:quit���˳�д��
void FilePractice() {
	//���ļ�
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
	char *p_chArr[] = { "��ϼ�������ɣ�\n","��ˮ������һɫ��\n","���۳����������֮����\n","���󾪺������Ϻ���֮��\n" };
	//���ļ�
	FILE *fp = fopen("poetry.txt", "w");
	int i = 0;
	int len = sizeof(p_chArr) / sizeof(p_chArr[0]);
	//�����ļ�
	while (i<len) {
		fputs(p_chArr[i], fp);
		i++;
	}
	//�ر��ļ�
	fclose(fp);
	

}
void main() {
	//FilesOpen();
	//FileInput();lianxi
	//FileReadChar();
	//FilePractice();
	FileFputs();
}