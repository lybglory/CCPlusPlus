#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void ChangeValue1(int pa,int pb) {	
	if (pa < pb) {
		int p = pa;
		pa = pb;
		pb = p;
	}
	printf("ChangeValue1的地址：pa=%x,pb=%x\n", &pa, &pb);
}

void main1() {
	printf("请随意输入2个整数：");
	int a, b;
	int* pa = &a, * pb = &b;
	scanf("%d,%d", pa, pb);//注意需要输入逗号，类型要匹配
	printf("main中的变量地址：a=%x; b=%x\n", &a, &b);
	printf("a=%d; b=%d\n", a, b);
	ChangeValue1(a,b);
	printf("改变以后：a=%d; b=%d\n", *pa, *pb);
}
