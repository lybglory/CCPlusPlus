#include <stdio.h>
int num = 10;
int *getNumPoint()
{
	printf("num addr=%p\n", &num);
	return &num;
}

void main()
{
	*(getNumPoint()) = 2020;
	printf("num = %d\n", num);
}
