#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
double recursValue = 0;
//�ݹ�ʵ�� 
double Fac(int n)//Ҫ����double���ͣ���Ȼ��� 
{
	if (n == 1)
	{
		recursValue= 1.0;//return 1 ��������д����� 
	}
	else if (n == 2)
	{
		recursValue= 2.0;//return 2 ��������д����� 
	}
	else
	{
		recursValue = Fac(n - 1) + Fac(n - 2);
	}
	return recursValue;
}
//forѭ��ʵ��
int For(int n)
{
	int n1 = 1;
	int n2 = 2;
	int n3;
	for (int i = 0; i < n; i++)
	{
		n3 = n1 + n2;
		n1 = n2;//��ǰ�ƶ�,n1���ڵ�ǰn2��ֵ�� 
		n2 = n3;//��ǰ�ƶ�,n2���ڵ�ǰn3��ֵ��
	}
	return n3;
}
//����ʵ��
int Array(int n)
{
	int a[50];
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < n; i++)//��2��ʼѭ�� 
	{
		a[i] = a[i - 1] + a[i - 2];
		int temp = i;
	}
	return a[n - 1];
}
void main3()
{
	int n;
	printf("������̨������");
	scanf("%d", &n);//���������������12 
	printf("�ݹ�ʵ��:�ߵ�%d�׵Ŀ�������:%2.0f\n", n, Fac(n));//�����50�������Լ10���Ӳ���
	printf("For ʵ��:�ߵ�%d�׵Ŀ�������:%d\n", n, For(n - 2));//for��10�ȼ���12,n1,n2��������,num��3��ʼ
	printf("����ʵ��:�ߵ�%d�׵Ŀ�������:%d\n", n, Array(n));
}