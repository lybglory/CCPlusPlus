#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��������Ϊ�������ݣ����ݵ���Ԫ�ص��׵�ַ����ַ4���ֽ�
//void printArrary(int arr[50],int n) {
void printArrary(int *arr, int n) {
	//�������������������������βλ��˻�Ϊָ��
	printf("printArrary�����С=%d\n",sizeof(arr));//4
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ",*arr+i);

	}
}

void main4() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printf("main:arr�����ܴ�С=%d\n",sizeof(arr));//5X4=20�ֽ�
	printArrary(arr,arrLength);
}