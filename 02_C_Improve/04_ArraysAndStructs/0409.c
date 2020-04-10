#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Multidimensional() {
	//先定义数组类型，再用数组类型定义数组指针
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//有typedef是定义类型，没有则是定义变量,下面代码定义了一个数组类型ArrayType
	typedef int(ArrayType)[10];
	//int ArrayType[10]; //定义一个数组，数组名为ArrayType

	ArrayType myarr; //等价于 int myarr[10];
	ArrayType* pArr = &arr; //定义了一个数组指针pArr，并且指针指向数组arr
	for (int i = 0; i < 10; i++) {
		printf("%d ", (*pArr)[i]);
	}
	printf("\n");

}

void ArrayPointDefine1() {
	int array[4] = { 2020,2019,2018,2017 };
	typedef int arr[4];
	arr *arr_p = &array;
	for (size_t i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		printf("%d\n", (*arr_p)[i]);
	}
}

void ArrayPointDefine2() {
	int arr[5] = { 1, 2, 3, 4, 5 };

	typedef int(*ARRAY)[5];

	ARRAY arr_P = &arr;

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*arr_P)[i]);
		printf("%d\n", *((*arr_P) + i));
	}
}

void ArrayPointDefine3() {
	int arr[5] = { 1, 2, 3, 4, 5 };

	int *arr_p = arr;

	//int arr[5] = { 1, 2, 3, 4, 5 };

	// 语法： 数组元素类型 （* 数组指针变量名称）[元素个数]
	//int(*p)[5] = &arr;
	// *p == arr
	for (int i = 0; i < 5; i++)
	{
		//printf("%d\n", (*p)[i]);
		printf("%d\n", arr_p[i]);
	}
}
void main_0409() {
	//Multidimensional();
	//ArrayPointDefine1();
	//ArrayPointDefine2();
	//ArrayPointDefine3();
}