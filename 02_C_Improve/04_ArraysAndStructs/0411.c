#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void NormalSort(int* p, int len) {
	for (int i = 0; i < len; i++)
	{	//2020,2016,2019,2017,2018
		for (size_t j = i+1; j < len; j++)
		{
			if (p[i] > p[j]) {
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}


void PrintfArray(int *arrP,int len) {
	printf("\n");
	for (size_t i = 0; i < len; i++)
	{
		printf("arrP[%d]=%d ",i,arrP[i]);
	}
}
void main() {
	int array[] = { 2020,2016,2019,2017,2018 };
	int arrayLen = sizeof(array) / sizeof(array[0]);

	NormalSort(array, arrayLen);
	PrintfArray(array,arrayLen);
}