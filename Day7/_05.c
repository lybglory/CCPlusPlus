#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Swap00(int *pa, int *pb) {//�����*pa��*pbͬ������ͬһ�������������ݵ��ǵ�ַ
	//int *p;      //����ָ������ʼ��
	//int p = *pa;
	printf("Swapǰ��pa=%d, *pa=%x;pb=%d *pb=%x\n",pa,pb,*pa, *pb);
	int *p = pa;
	pa = pb;
	pb = p;
	printf("Swap��pa=%d, *pa=%x;pb=%d *pb=%x\n", pa, pb, *pa, *pb);
}

void main05() {
	printf("����������2��������");
	int a, b;
	int *pa = &a;int *pb = &b;
	scanf("%d,%d", pa, pb);
	printf("main��a=%d, &a=%x; b=%d, &b=%x\n",a,b, &a, &b);
	printf("a=%d; b=%d\n", a, b);
	if (a < b) {
		//Swap00(&a, &b);
		Swap00(pa, pb);//ͬ�����Խ����ɹ�
	}
	printf("�����Ժ�a=%d, &a=%x; b=%d, &b=%x\n", a, b, &a, &b);
	//�����a=2020;b=2019
}

