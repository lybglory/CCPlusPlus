#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Swap12(int *pa, int *pb) {
		int p = *pa;
		*pa = *pb;
		*pb = p;
	printf("Swap：pa=%x,pb=%x\n", pa, pb);
}
void Swap13(int *pa, int *pb) {
	int *p = pa;
	pa = pb;
	pb = p;
	printf("Swap：pa=%x,pb=%x\n", pa, pb);
}

void main2() {
	printf("请随意输入2个整数：");
	int a, b;
	int *pa = &a, *pb = &b;
	scanf("%d,%d", pa, pb);
	printf("main：a=%x; b=%x\n", &a, &b);
	printf("a=%d; b=%d\n", a, b);
	if (a<b) {
		//Swap(pa, pb);
		Swap12(pa,pb);
	}
	printf("交换以后：a=%d; b=%d\n", a, b);
	//结果：a=2020;b=2019
}
