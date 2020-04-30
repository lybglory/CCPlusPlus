#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SelectSortInt(int *p_arr,int length) {
	for (int i = 0; i < length; i++)
	{
		int min=i;
		for (int j = 1+i; j < length; j++)
		{
			if (p_arr[min]>p_arr[j]) {
				min = j;
			}
		}
		if (i != min) {
			int temp = p_arr[i];
			p_arr[i] = p_arr[min];
			p_arr[min] = temp;
		}
	}
}
void PrintfArr(int *p_arr,int length) {
	for (int i = 0; i < length; i++)
	{
		printf("p_arr[%d]=%d\n",i,p_arr[i]);
	}
}

void CallbkArrSort(void(* pFunc)(void *),void *pArr,int len,int eleSize) {
	char *temp = (char*)malloc(eleSize);
	for (int i = 0; i < len; i++)
	{
		int min = i;					//
		for (int j = 1+i; j < len; j++)
		{
			char *pMin = (char*)pArr + i * eleSize;
			char *p2 = (char*)pArr + eleSize * j;
			if (SortIntArr(pMin,p2)==1) {
				min = j;
			}
		}
		if (i!=min) {
			char *pi = (char *)pArr + i * eleSize;
			char *pmin = (char*)pArr + min * eleSize;
			memcpy(pi, pmin, eleSize);
			memcpy(pmin, pmin, eleSize);

		}

	}
}

int SortIntArr(void *p1,void *p2) {
	int *n1 = (int *)p1;
	int *n2 = (int *)p2;

	if (*n1>*n2) {
		return 1;
	}
	else {
		return 0;
	}

}
void Test01() {
	int year[] = {2010,2020,2017,2018,2016,2019};
	int len = sizeof(year) / sizeof(year[0]);
	SelectSortInt(year,len);
	PrintfArr(year, len);
}
void Test02() {
	
}

void main_0429() {
	//Test01();
	Test02();
}