#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Func.h"
void GetArryMax() {
	int numbers[5] = { 'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26 };
	int *p;
	p = numbers;
	int length = sizeof(numbers) / sizeof(int);//长度
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", numbers[i]);
	}
	int max = GetMax(p, length);
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
void PointerUse() {
	int a = 0;
	char b = 100;
	printf("%p, %p\n", &a, &b); //打印a, b的地址

	//int *代表是一种数据类型，int*指针类型，p才是变量名
	//定义了一个指针类型的变量，可以指向一个int类型变量的地址
	int *p;
	p = &a;//将a的地址赋值给变量p，p也是一个变量，值是一个内存地址编号
	
	printf("%d\n", *p);//p指向了a的地址，*p就是a的值

	char *p1 = &b;
	printf("%c\n", *p1);//*p1指向了b的地址，*p1就是b的值
	scanf("输入：%c\n",*p1);
	printf("%c\n", *p1);//*p1指向了b的地址，*p1就是b的值

}
void PointerTest() {
	int *p;
	int m = 2020;
	printf("m的地址=%p \n",&m);
	p = &m;
	printf("m=%d, *p=%d \n", m, *p);
	printf("m的地址=%p, p的地址=%p \n",&m,p);
	//scanf("%d",&m);
	scanf("%d", p);
	printf("m=%d, *p=%p \n", m, *p);


}
void main() {
	//GetArryMax();
	//PointerSize();
	//PointerModify();
	//PointerUse();
	PointerTest();
}