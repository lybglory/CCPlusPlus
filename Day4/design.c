#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void ifSelect() {
	int a = 1;
	int b = 2;

	if (a > b)
	{
		printf("a>b,a=%d,b=%d\n", a, b);
	}
	else {
		printf("a<b,a=%d,b=%d\n", a,b);
	}
}

void ifElseIfElse() {
	unsigned int a;
	scanf("%u", &a);

	if (a < 10)
	{
		printf("个位\n");
	}
	else if (a < 100)
	{
		printf("十位\n");
	}
	else if (a < 1000)
	{
		printf("百位\n");
	}
	else
	{
		printf("很大\n");
	}

}

void SanMuMatch() {
	int year = 0;
	printf("please input year:");
	scanf("%d",&year);
	printf(year >2018?"2019年":"2018年");
}

void WhileFunc() {
	int a = 20;
	while (a > 10)
	{
		scanf("%d", &a);
		printf("a = %d\n", a);
	}
}
void main() {
	//ifElseIfElse();
	//SanMuMatch();
	WhileFunc();
}