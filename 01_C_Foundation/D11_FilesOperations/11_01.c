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
		printf("��ǰд���ַ�����=%d\n",files);
	}
	

	fclose(wfp);
}

void Testfscanf() {
	struct Person rec[3];
	memset(rec,0,sizeof(rec));				//�ڴ�ռ��ʼ��
	printf("sizeof(rec)=%d\n",sizeof(rec));
	FILE *rfp = fopen("fprintf.txt", "r");	//д���ļ�
	if (rfp == NULL) {
		perror("read error!");
		return;
	}

	//feof����ֵ ����ֵ�����ˣ�����0û�ж���
	int n = 0;
	while(feof(rfp)==0) {
		//��ȡ���������ݸ�ֵ���ṹ���Ա
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


#define len 50
void Sortcontent(int* p_arr, int m) {

	//j���ƱȽ���������һ�˱Ƚ���ȷ�����ֵ
	for (size_t j = 0; j < m - 1; j++)
	{
		//���ƽ�������
		for (size_t k = 0; k < m - 1 - j; k++)
		{	//������
			if (p_arr[k] > p_arr[k + 1]) {
				int temp = 0;
				temp = p_arr[k];
				p_arr[k] = p_arr[k + 1];
				p_arr[k + 1] = temp;
			}
		}
		printf("sort:p_arr[%d]=%d\n", j, p_arr[j]);
	}
}

void RandNumGenerate() {

	FILE *wfp = fopen("CreateNum.txt","w");
	if (wfp == NULL) {
		perror("read error!");
		return;
	}
	srand(time(NULL));
	int i = 0;
	while (i< len) {
		fprintf(wfp, "%d\n", rand() % 100);
		i++;
	}
	fclose(wfp);

	//����
	FILE *rfp = fopen("CreateNum.txt", "r");
	if (rfp == NULL) {
		perror("read error!");
		return;
	}
	int num[50] = {0};
	for (size_t i = 0; i < len; i++)
	{
		fscanf(rfp, "%d\n", &num[i]);
		printf("Bef:num[%d]=%d\n", i, num[i]);
	}

	fclose(rfp);
	//j���ƱȽ���������һ�˱Ƚ���ȷ�����ֵ
	//for (size_t j = 0; j < len -1; j++)
	//{
	//	//���ƽ�������
	//	for (size_t k = 0; k < len -1-j; k++)
	//	{	//������
	//		if (num[k]>num[k+1]) {
	//			int temp = 0;
	//			temp=num[k];
	//			num[k] = num[k + 1];
	//			num[k + 1] = temp;
	//		}
	//	}
	//	printf("sort:num[%d]=%d\n", j, num[j]);
	//}

	Sortcontent(num,len);
	//�����д���ļ�
	FILE *sortfp = fopen("sort.txt","w");
	if (sortfp==NULL) {
		perror("write error!");
		return;
	}
	for (size_t i = 0; i < len; i++)
	{
		fprintf(sortfp,"%d\n",num[i]);
	}
	fclose(sortfp);
}



void main_1101() {
	//TestFwrite();
	//TestFRead();
	//Testfprintf();
	//Testfscanf();
	//RandNumGenerate();
}

