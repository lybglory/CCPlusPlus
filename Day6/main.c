#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Func.h"
void GetArryMax() {
	int numbers[5] = { 'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26 };
	int *p;
	p = numbers;
	int length = sizeof(numbers) / sizeof(int);//����
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", numbers[i]);
	}
	int max = GetMax(p, length);
	printf("\n max=%d", max);
}

void PointerSize() {
	int *p1;
	int **p2;
	char *p3;
	char **p4;
	printf("sizeof(p1) = %d\n", sizeof(p1));
	printf("sizeof(p2) = %d\n", sizeof(p2));
	printf("sizeof(p3) = %d\n", sizeof(p3));
	printf("sizeof(p4) = %d\n", sizeof(p4));
	printf("sizeof(double *) = %d\n", sizeof(double*));

}

void PointerModify() {
	int a = 0;
	int b = 11;
	int* p = &a;

	*p = 100;
	printf("a = %d, *p = %d\n", a, *p);

	p = &b;
	*p = 22;
	printf("b = %d, *p = %d\n", b, *p);

}
void PointerUse() {
	int a = 0;
	char b = 100;
	printf("%p, %p\n", &a, &b); //��ӡa, b�ĵ�ַ

	//int *������һ���������ͣ�int*ָ�����ͣ�p���Ǳ�����
	//������һ��ָ�����͵ı���������ָ��һ��int���ͱ����ĵ�ַ
	int *p;
	p = &a;//��a�ĵ�ַ��ֵ������p��pҲ��һ��������ֵ��һ���ڴ��ַ���
	
	printf("%d\n", *p);//pָ����a�ĵ�ַ��*p����a��ֵ

	char *p1 = &b;
	printf("%c\n", *p1);//*p1ָ����b�ĵ�ַ��*p1����b��ֵ
	scanf("���룺%c\n",*p1);
	printf("%c\n", *p1);//*p1ָ����b�ĵ�ַ��*p1����b��ֵ

}
void PointerTest() {
	int *p;
	int m = 2020;
	printf("m�ĵ�ַ=%p \n",&m);
	p = &m;
	printf("m=%d, *p=%d \n", m, *p);
	printf("m�ĵ�ַ=%p, p�ĵ�ַ=%p \n",&m,p);
	//scanf("%d",&m);
	scanf("%d", p);
	printf("m=%d, *p=%p \n", m, *p);


}
void main() {
	//GetArryMax();
	//PointerSize();
	//PointerModify();
	//PointerUse();
	PointerTest();
}