#include <stdio.h>

void swap01(int x, int y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
	printf("x = %d, y = %d\n", x, y);
}

void swap02(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void main06()
{
	int a = 3;
	int b = 5;
	swap01(a, b); //值传递
	printf("a = %d, b = %d\n", a, b);

	a = 3;
	b = 5;
	swap02(&a, &b); //地址传递
	printf("a2 = %d, b2 = %d\n", a, b);
}
