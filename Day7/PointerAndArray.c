#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ArrayPointer1() {
	int num[5] = {1980,1990,2000,2010,2020};
	int *p = num;
	printf("*p++=%d\n",*p++);
	printf("(*p)++=%d\n", (*p)++);
	printf("*(++p)=%d\n", *(++p));

}

void ArrayPointer2() {
	int num[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	printf("%d\n",num[*(num+num[*(num+num[3])])]);
	printf("*(num+4)=%d",*(num+4));
}

void main() {
	//ArrayPointer1();
	ArrayPointer2();
}