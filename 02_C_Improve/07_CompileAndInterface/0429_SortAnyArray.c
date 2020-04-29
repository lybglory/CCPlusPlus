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

void CommArrSort(void(* pFunc)(void *,void *),void *pArr,int len,int eleSize) {
	char *temp = (char*)malloc(eleSize);
	for (int i = 0; i < len; i++)
	{
		int min = i;					//
		for (int j = 1+i; j < len; j++)
		{
			char *pMin = (char*)pArr + min * eleSize;
			char *pj = (char*)pArr + eleSize * j;
			if (CallbkSortIntArr(pMin,pj)) {
				min = j;
			}
		}
		if (i!=min) {
			char *pi = (char *)pArr + i * eleSize;
			char *pmin = (char *)pArr + min * eleSize;
			memcpy(temp,pi,eleSize);
			memcpy(pi, pmin, eleSize);
			memcpy(pmin, temp, eleSize);
		}
	}//for_end
	if (temp!=NULL) {
		free(temp);
		temp = NULL;
	}
}

int CallbkSortIntArr(void *p1,void *p2) {
	int *n1 = (int *)p1;
	int *n2 = (int *)p2;

	if (*n1>*n2) {
		return 1;
	}
	else {
		return 0;
	}

}
void CommPrintfArr(void(* callbkFunc)(void *),void *pArr,int len,int eleSize) {
	for (int i = 0; i < len; i++)
	{
		char *arrEle = (char*)pArr + i * eleSize;
		callbkFunc(arrEle);
	}
}
void CallbkPrintfArr(void(* data)) {
	int* num = (int *)data;
	printf("%d ",*num);
}
void Test01() {
	int year[] = {2010,2020,2017,2018,2016,2019};
	int len = sizeof(year) / sizeof(year[0]);
	SelectSortInt(year,len);
	PrintfArr(year, len);
}
void Test02() {
	int years[5] = {0};
	int len=sizeof(years)/sizeof(years[0]);
	printf("Enter %d element:\n",len);
	for (int i = 0; i < len; i++){
		scanf("%d", &years[i]);
	}
	printf("Sort before:");
	CommPrintfArr(CallbkPrintfArr, years, len, sizeof(years[0]));
	CommArrSort(CallbkSortIntArr, years, len, sizeof(years[0]));
	printf("\nSort after :");
	CommPrintfArr(CallbkPrintfArr, years, len, sizeof(int));


}

void main() {
	//Test01();
	Test02();
}