#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>//设置本地化
void Testrewind() {
	//"w+":可写 可读
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
	//文件流定位到尾部
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	printf("file length=%d\n",len);

	//向堆区申请空间
	char *p_chr = (char*)malloc(len);

	//空间初始化
	memset(p_chr, 0,len);

	//一次性将文本内容全部读取出来
	//先将文件流复位
	rewind(fp);
	//fread(void *ptr,块数据的大小,多少块, FILE *stream);
	//fread读取的内容是汉字，如果编码格式不是ANSI(windows),读取出来的数据一定会出现乱码。
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