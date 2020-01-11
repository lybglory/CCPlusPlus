#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int sum = 0;
int i = 1;
int temp = 0;
int Fac(int num) {
	temp = num;
	if (num == 1) {
		printf("当n=%d,Fac(%d)=1;退出递归\n", num, num);
		sum= 1;
	}
	else {
		printf("第%d次递归,Fac(%d)=n+Fac(n-1)=%d+Fac(%d-1),此时n=%d\n", i++, num, num, num, temp - 1);
		sum = num + Fac(num - 1);
		printf("依次退出第%d次递归,Fac(%d)=%d+Fac(%d-1)=%d\n", --i, num, num, num, sum);
		
	}
	return  sum;
}
void main2()
{
	int m;
	scanf("%d", &m);
	printf("递归求1+...+%d=%d\n", m, Fac(m));
}
