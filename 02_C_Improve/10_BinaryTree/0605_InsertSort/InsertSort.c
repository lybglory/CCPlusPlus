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

void main() {
	int numArr[] = {2009,2006,2012};
}