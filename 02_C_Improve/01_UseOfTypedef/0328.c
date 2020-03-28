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

	//1. 直接修改
	a = 20;
	printf("直接修改,a:%d\n", a);

	//2. 间接修改
	int* p = &a;
	*p = 30;

	printf("间接修改,a:%d\n", a);
}


void main() {
	TestConst();
}