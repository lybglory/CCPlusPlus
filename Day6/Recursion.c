#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Factorial(int n)
{
	if (n == 1) {
		return 1L; /*“1L”为长整型常量*/
	}else {
		return n + Factorial(n - 1);
	}
}
void main()
{
	int m;
	scanf("%d", &m);
	printf("%d!=%d\n", m, Factorial(m));
}
