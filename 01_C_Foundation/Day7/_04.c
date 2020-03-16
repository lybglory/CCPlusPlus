#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//数组名作为参数传递，传递的是元素的首地址。地址4个字节
//void printArrary(int arr[50],int n) {
void printArrary(int *arr, int n) {
	//数组名做函数参数，函数的形参会退化为指针
	printf("printArrary数组大小=%d\n",sizeof(arr));//4
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ",*arr+i);

	}
}

void main4() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printf("main:arr数组总大小=%d\n",sizeof(arr));//5X4=20字节
	printArrary(arr,arrLength);
}