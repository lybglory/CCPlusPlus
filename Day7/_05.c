#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Swap00(int *pa, int *pb) {//这里的*pa和*pb同样不是同一个变量，它传递的是地址
	//int *p;      //报错，指针必须初始化
	//int p = *pa;
	int *p = pa;
	pa = pb;
	pb = p;
	printf("Swap：pa=%x,pb=%x\n", &pa, &pb);
}

void main5() {
	printf("请随意输入2个整数：");
	int a, b;
	int* pa = &a, * pb = &b;
	scanf("%d,%d", pa, pb);
	printf("main：a=%x; b=%x\n", &a, &b);
	printf("a=%d; b=%d\n", a, b);
	if (a < b) {
		//Swap00(&a, &b);
		Swap00(pa, pb);//同样可以交换成功
	}
	printf("交换以后：a=%d; b=%d\n", a, b);
	//结果：a=2020;b=2019
}

