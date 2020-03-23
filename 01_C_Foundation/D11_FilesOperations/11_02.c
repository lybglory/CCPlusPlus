#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>//���ñ��ػ�
void Testrewind() {
	//"w+":��д �ɶ�
	FILE *fp = fopen("note.txt","w+");
	if (fp==NULL) {
		perror("fopen error!");
		return;
	}

	fputs("Date:2020/03/22 16:10\nToday is sunny day",fp);
	//fclose(fp);
	rewind(fp);
	fp= fopen("note.txt", "r");
	char chr[100] = ""; 
	while (fgets(chr, sizeof(chr), fp)) {
		printf("chr=%s", chr);
	}
	fclose(fp);
}

void Testfseek() {
	FILE *fp = fopen("note.txt","w+");
	if (fp==NULL) {
		perror("fopen error!");
		return;
	}

	fputs("Date:2020/03/22 17:00\nToday is sunny day",fp);
	//fclose(fp);
	//rewind(fp);
	fseek(fp,0, 0);
	fp= fopen("note.txt", "r");
	//fseek(fp, -18, SEEK_END);//"Today is sunny day"
	fseek(fp, 5, SEEK_SET);
	char chr[100] = ""; 
	while (fgets(chr, sizeof(chr), fp)) {
		printf("chr=%s", chr);
	}
	fclose(fp);
}
void TestFtell() {
	FILE *fp = fopen("prose.txt","r");
	//�ļ�����λ��β��
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	printf("file length=%d\n",len);

	//���������ռ�
	char *p_chr = (char*)malloc(len);

	//�ռ��ʼ��
	memset(p_chr, 0,len);

	//һ���Խ��ı�����ȫ����ȡ����
	//�Ƚ��ļ�����λ
	rewind(fp);
	//fread(void *ptr,�����ݵĴ�С,���ٿ�, FILE *stream);
	//fread��ȡ�������Ǻ��֣���������ʽ����ANSI(windows),��ȡ����������һ����������롣
	fread(p_chr, len, 1, fp);
	printf("%s\n",p_chr);
	if (p_chr!=NULL) {
		free(p_chr);
		p_chr = NULL;
	}
}
void main_11_02() {
	//Testrewind();
	//Testfseek();
	TestFtell();
}