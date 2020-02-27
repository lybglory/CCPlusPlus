#include <stdio.h>
int num = 10;
int *getNumPoint()
{
	printf("num addr=%p\n", &num);
	return &num;
}

void main_07_07()
{
	*(getNumPoint()) = 2020;
	printf("num = %d\n", num);
}
