#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ArrayIndexTest() {
	int arr[] = { 5, 3, 6, 8, 2, 9 };
	int* p = arr + 2;
	printf("*p = %d\n", *p);
	printf("*p = %d\n", p[-1]);
}
void main_0408() {
	ArrayIndexTest();
}