#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void TestConst() {
	const int num = 2020;
	int	*p = &num;
	*p = 2019;
	printf("num=%d\n",num);
}

void test() {

	int a = 10;

	//1. ֱ���޸�
	a = 20;
	printf("ֱ���޸�,a:%d\n", a);

	//2. ����޸�
	int* p = &a;
	*p = 30;

	printf("����޸�,a:%d\n", a);
}


void main() {
	TestConst();
}