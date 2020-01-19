#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ArrayPointer1() {
	int num[5] = {1980,1990,2000,2010,2020};
	int *p = num;
	printf("*p++=%d\n",*p++);
	printf("(*p)++=%d\n", (*p)++);
	printf("*(++p)=%d\n", *(++p));

}

void main() {
	ArrayPointer1();
}