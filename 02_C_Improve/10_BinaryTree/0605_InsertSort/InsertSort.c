#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertSort(int *arr,int length) {
	for (int i = 0; i < length; i++)
	{	//前后比较。后面的数更小时
		if (arr[i-1]>arr[i]) {
			int temp = arr[i];
			int j;

			//for循环还得进行一次判断。
			for ( j=0; j>=0&&arr[j]>temp; j++)
			{
				arr[j + 1] = arr[j];//更大的数往后移
			}
		}

	}//for_i_end
}

void IterateArrComm(void *arr,void( *calbkIterate)(void *),int length,int eleSize) {
	char *pArr = arr;
	for (int i = 0; i < length; i++)
	{
		char *temAddr = pArr + eleSize * i;//得到元素的地址
		calbkIterate(temAddr);
	}
}

void CalbkIntArr(void *element) {
	int *n = (int *)element;
	printf("%d ",*n);
}
void main() {
	int numArr[] = {2009,2006,2012,2020,2018,2015,2016,2019};
	int arrLen = sizeof(numArr) / sizeof(numArr[0]);
	IterateArrComm(numArr,CalbkIntArr,arrLen,sizeof(int));
}