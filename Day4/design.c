#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void ifSelect() {
	int a = 1;
	int b = 2;

	if (a > b)
	{
		printf("a>b,a=%d,b=%d\n", a, b);
	}
	else {
		printf("a<b,a=%d,b=%d\n", a,b);
	}
}

void ifElseIfElse() {
	unsigned int a;
	scanf("%u", &a);

	if (a < 10)
	{
		printf("��λ\n");
	}
	else if (a < 100)
	{
		printf("ʮλ\n");
	}
	else if (a < 1000)
	{
		printf("��λ\n");
	}
	else
	{
		printf("�ܴ�\n");
	}

}

void SanMuMatch() {
	int year = 0;
	printf("please input year:");
	scanf("%d",&year);
	printf(year >2018?"2019��":"2018��");
}

void WhileFunc() {
	int a = 20;
	while (a > 10)
	{
		scanf("%d", &a);
		printf("a = %d\n", a);
	}
}
void WhileFunc1() {
	int num = 1;
	int sum = 0;
	while (num<=100) {
		sum += num;
		num++;
	}
	printf("sum=%d",sum);//sum=5050
}

void DoWhileFunc() {
	int a = 10;
	do
	{
		printf("a = %d\n", a);
		a++;
	} while (a < 10);
	printf("======\n");
	int b = 10;
	while (b<10) {
		printf("b = %d\n", b);
		b++;
	}
}
/*
#####
 ####
  ###
   ##
    #
*/
void ForFunc() {
	//int n = 5;
	for (int i = 0; i < 5; i++)
	{	//�״ν���Ƕ�ף�i=0,j=0,�ж�������Ҫ<=�Ż�ִ��
		for (int j = 0; j <= i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
	printf("========\n");
	//���ѭ������������
	for (int i = 0; i < 5; i++)
	{	//�ڲ�ѭ������ÿ�еĸ���
		for (int j = 0; j < 5; j++)
		{	//�״�forѭ��Ƕ��,��һ�У���Ҫ��ӡ5��#,�Ż�������һ��forѭ��
			//��һ�Σ�i=0��j=0 .��j=4���Ѿ���ӡ5��#����j=5,����������,�����ڲ�ѭ��
			//�ڶ��Σ������ڲ�ѭ����i=1��
			if (j>=i) {
				//
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintfZhiShu() {
	int m, n;
	//�����������2��ʼ���������Լ���ǰһλ
	//����������1���⣬ֻ�ܱ�1�ͱ�����������
	for (m = 2; m <= 100; m++)
	{	
		//1����m=2;n=2;�����ڲ�forѭ�����ж�m % n����0������ѭ����
		//	�ж����ѭ�����if�������������Լ��������֣�������,��ӡ�����m++
		//2����m=3;n=2����������ڲ�if�ж�3%2��n++��n=3֮��������
		//	����������if�жϣ�m==n������������ӡ���,m++
		//3����m=4��n=2�������ڲ�if�ж�4%2�������ڲ�ѭ����
		//	�ж����if��m��n����ȣ���������
		//4����m=5,n=2,��������ڲ�if�ж�5%2,5%3,5%4��n++��n=5֮������
		// �ж����if��m=n=5����������,��ӡ���,m++
		for (n = 2; n < m; n++)
		{
			//m�ܹ����� ��1�����ĳ����n��һ����������
			if (m % n == 0)//��������
			{	//������֮ǰ����ȫ��ȫ������2�꣬��û������
				//����
				break;
			}
		}
		
		//�ж�n�Ƿ����䱾��m,����ǣ���Ϊ����
		if (m == n) {
			//ֻ���������
			printf("%d; ", m);
		}
	}
}


void ContinueWhile() {
	// while continueʵ�ּ���1��100(��)֮��ģ������ܱ�7����֮�����������ĺ�
	int i = 1;
	int sum = 0;
	int sum7 = 0;
	while (i<=100) {
		if (i%7==0) {
			//�ܱ�7�����������������ۼӣ�����ѭ����������һ��ѭ��
			//i��Ҫ+1
			i++;
			continue;
		}
		//֮���ۼ����ˣ�iͬ����Ҫ����+1
		sum += i;
		i++;
	}
	printf("sum=%d", sum);
}

void main() {
	//ifElseIfElse();
	//SanMuMatch();
	//DoWhileFunc();
	//ForFunc();
	//PrintfZhiShu();
	ContinueWhile();
}