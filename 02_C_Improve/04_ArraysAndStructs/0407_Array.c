#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void LinearArray01() {
	//
	int array[5] = { 2016,2017,2018,2019,2020 };
	int* p = array;
	printf("sizeof(array):%d\n", sizeof(array)); 	//��ʱsizeof���Ϊ��������ĳ���
	printf("&array  =%d\n",&array);
	printf("&array+1=%d\n", &array+1);
}
void main_0407() {
	LinearArray01();
}