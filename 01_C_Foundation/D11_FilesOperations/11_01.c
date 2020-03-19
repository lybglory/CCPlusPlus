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
	struct Person prs[5];		//������Ŷ�ȡ����������
	memset(prs,0,sizeof(prs));	//�ڴ�ռ���Ҫ��ʼ��
	FILE *rfp = fopen("Info.txt", "r");	//��ȡ �������ļ�
	if (rfp == NULL) {
		perror("read error!");
		return;
	}
	
	int count = sizeof(prs) / sizeof(prs[0]);
	//��Ȼ��ȡ�Ŀ�����ʵ��Ҫ�ࡣ��ʵ�������ж��ٶ�����
	//fread()���ص���ʵ�ʶ�ȡ���Ŀ���
	int actualNum=fread(prs,sizeof(struct Person),count,rfp);
	//��������ȡ����
	for (size_t i = 0; i < actualNum; i++){
		printf("%s %d %c\n",prs[i].name,prs[i].age,prs[i].sex);
	}

	fclose(rfp);
}
void main() {
	//TestFwrite();
	TestFRead();
}

