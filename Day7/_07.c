#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ChangeNum(int *PointA) {
	*PointA = 2020;
}

//������Ϊ�������ݣ����ݵ���Ԫ�ص��׵�ַ����ַ4���ֽ�
//void printArrary(int a[10], int n)
//void printArrary(int a[], int n)
void printArrary2(int* a, int n)
{
	printf("printArrary�����С=%d\n", sizeof(a));//������:4
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

main_07() {
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = sizeof(a) / sizeof(a[0]);
	//�������������������뽫���鳤�ȴ��ݹ�ȥ
	printArrary2(a, n);

}
main_1() {
	int num = 2019;
	printf("�ı�ǰ��num=%d\n", num);
	ChangeNum(&num);
	printf("�ı��num=%d",num);
}