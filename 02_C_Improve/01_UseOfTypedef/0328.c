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
void main() {
	TestConst();
}