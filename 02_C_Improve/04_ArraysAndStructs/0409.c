#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Multidimensional() {
	//�ȶ����������ͣ������������Ͷ�������ָ��
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//��typedef�Ƕ������ͣ�û�����Ƕ������,������붨����һ����������ArrayType
	typedef int(ArrayType)[10];
	//int ArrayType[10]; //����һ�����飬������ΪArrayType

	ArrayType myarr; //�ȼ��� int myarr[10];
	ArrayType* pArr = &arr; //������һ������ָ��pArr������ָ��ָ������arr
	for (int i = 0; i < 10; i++) {
		printf("%d ", (*pArr)[i]);
	}
	printf("\n");

}
void main() {
	Multidimensional();
}