#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void ChangeValue1(int pa,int pb) {	
	if (pa < pb) {
		int p = pa;
		pa = pb;
		pb = p;
	}
	printf("ChangeValue1�ĵ�ַ��pa=%x,pb=%x\n", &pa, &pb);
}

void main1() {
	printf("����������2��������");
	int a, b;
	int* pa = &a, * pb = &b;
	scanf("%d,%d", pa, pb);//ע����Ҫ���붺�ţ�����Ҫƥ��
	printf("main�еı�����ַ��a=%x; b=%x\n", &a, &b);
	printf("a=%d; b=%d\n", a, b);
	ChangeValue1(a,b);
	printf("�ı��Ժ�a=%d; b=%d\n", *pa, *pb);
}
