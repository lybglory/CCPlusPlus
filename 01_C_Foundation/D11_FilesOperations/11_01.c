#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person {
	char name[10];
	int age;
	char sex;
};
void TestFwrite() {
	struct Person Star[3] = { {"Messi",33,'M'},
							  {"Bin",30,'M'},
							  {"Mei",30,'F'} };
	int count = sizeof(Star) / sizeof(Star[0]);
	FILE *wfp = fopen("Info.txt","w");
	if (wfp==NULL) {
		perror("read error!");
		return;
	}

	fwrite(Star, sizeof(struct Person), count, wfp);
	fclose(wfp);
}
void TestFRead() {	
	struct Person prs[5];		//用来存放读取出来的数据
	memset(prs,0,sizeof(prs));	//内存空间需要初始化
	FILE *rfp = fopen("Info.txt", "r");	//读取 二进制文件
	if (rfp == NULL) {
		perror("read error!");
		return;
	}
	
	int count = sizeof(prs) / sizeof(prs[0]);
	//虽然读取的块数比实际要多。但实际上是有多少读多少
	//fread()返回的是实际读取到的块数
	int actualNum=fread(prs,sizeof(struct Person),count,rfp);
	//仅遍历读取到的
	for (size_t i = 0; i < actualNum; i++){
		printf("%s %d %c\n",prs[i].name,prs[i].age,prs[i].sex);
	}

	fclose(rfp);
}
void Testfprintf() {
	struct Person prs[3] = { {"Chan",1,'F'},
							  {"Bin",30,'M'},
							  {"Mei",30,'F'} };
	FILE *wfp = fopen("fprintf.txt", "w");	
	if (wfp == NULL) {
		perror("read error!");
		return;
	}
	int len = sizeof(prs) / sizeof(prs[0]);
	for (size_t i = 0; i < len; i++){
		int files=fprintf(wfp, "name=%s age=%d sex=%c\n", prs[i].name,prs[i].age,prs[i].sex);
		printf("当前写入字符总数=%d\n",files);
	}
	

	fclose(wfp);
}

void Testfscanf() {
	struct Person rec[3];
	memset(rec,0,sizeof(rec));				//内存空间初始化
	printf("sizeof(rec)=%d\n",sizeof(rec));
	FILE *rfp = fopen("fprintf.txt", "r");	//写入文件
	if (rfp == NULL) {
		perror("read error!");
		return;
	}

	//feof返回值 非零值读完了；等于0没有读完
	int n = 0;
	while(feof(rfp)==0) {
		//读取出来的数据赋值给结构体成员
		//printf("n=%d\n",n);
		fscanf(rfp,"name=%s age=%d sex=%c\n",rec[n].name,&rec[n].age,&rec[n].sex);
		n++;
	}

	int files = n;
	for (size_t i = 0; i < files; i++)
	{
		printf("%s %d %c\n", rec[i].name, rec[i].age, rec[i].sex);
	}
	fclose(rfp);
}
void main() {
	//TestFwrite();
	//TestFRead();
	//Testfprintf();
	Testfscanf();
}

