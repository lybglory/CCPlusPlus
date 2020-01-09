#include <stdio.h>
#include <stdlib.h>
#include "Func.h"
void GetArryMax() {
	int numbers[5] = { 'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26 }, * p;
	p = numbers;
	int length = sizeof(numbers) / sizeof(int);//³¤¶È
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", numbers[i]);
	}
	int max = GetMax(numbers, length);
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
void main() {
	//GetArryMax();
	//PointerSize();
	PointerModify();
}