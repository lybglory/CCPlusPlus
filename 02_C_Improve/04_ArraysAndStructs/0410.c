#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void DyadicArray() {
	//��ά�����ʼ��
	int arr1[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	int arr2[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr3[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//��ӡ��ά����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
}

void main_0410() {
	DyadicArray();
}