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
void BubbleSort(int* p, int len) {
	for (size_t x = 0; x < len-1; x++)
	{
		for (size_t y = 0; y < len-1-x; y++)
		{
			if (p[y] > p[y+1]) {
				int temp = p[y];
				p[y] = p[y+1];
				p[y+1] = temp;
			}
		}
	}
}
void SelectionSort(int *p,int len) {
	for (int i = 0; i < len; i++)
	{	//2020,2016,2019,2017,2018
		int min = i;						//第一个下标
		for (size_t j = i+1; j < len; j++)
		{
			if (p[min]> p[j]) {
				min = j;
			}
		}
		if (i!=min) {
			int temp = p[i];
			p[i] = p[min];
			p[min] = temp;
		}
	}
}

void PrintfArray(int *arrP,int len) {
	for (size_t i = 0; i < len; i++)
	{
		printf("arrP[%d]=%d ",i,arrP[i]);
	}
}

void PtArrSelectionSort(char **p, int len) {
	for (size_t i = 0; i < len; i++)
	{
		int min = i;
		for (size_t j = i+1; j < len; j++)
		{	//比较字符，比较的是ASCII码,如果>0,说明有更小的元素
			if (strcmp(p[min], p[j])>0) {
				min = j;
			}
		}
		if (i!=min) {
			char *temp = p[i];
			p[i] = p[min];
			p[min] = temp;
		}
	}

}

void PrintfPointerArr(char **p,int len) {
	for (size_t i = 0; i < len; i++)
	{
		printf("p[%d]=%s\n", i, p[i]);
	}
}
void PointerArr() {
	char *str[] = {"Date:2020/4/12","Time:0:35","Missing glue pudding"};
	int len = sizeof(str) / sizeof(char*);
	PtArrSelectionSort(str,len);
	PrintfPointerArr(str, len);
}
void main_0411() {
	//int array[] = { 2020,2016,2019,2017,2018 };
	//int arrayLen = sizeof(array) / sizeof(array[0]);
	//NormalSort(array,arrayLen);
	//BubbleSort(array, arrayLen);
	//SelectionSort(array,arrayLen);
	//PrintfArray(array,arrayLen);
	PointerArr();
}