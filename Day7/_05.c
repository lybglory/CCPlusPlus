#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Swap00(int *pa, int *pb) {//�����*pa��*pbͬ������ͬһ�������������ݵ��ǵ�ַ
	//int *p;      //����ָ������ʼ��
	//int p = *pa;
	int *p = pa;
	pa = pb;
	pb = p;
	printf("Swap��pa=%x,pb=%x\n", &pa, &pb);
}

void main5() {
	printf("����������2��������");
	int a, b;
	int* pa = &a, * pb = &b;
	scanf("%d,%d", pa, pb);
	printf("main��a=%x; b=%x\n", &a, &b);
	printf("a=%d; b=%d\n", a, b);
	if (a < b) {
		//Swap00(&a, &b);
		Swap00(pa, pb);//ͬ�����Խ����ɹ�
	}
	printf("�����Ժ�a=%d; b=%d\n", a, b);
	//�����a=2020;b=2019
}

