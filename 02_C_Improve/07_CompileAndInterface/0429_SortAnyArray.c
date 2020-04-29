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
void Test01() {
	int year[] = { 2010,2020,2017,2018,2016,2019 };
	int len = sizeof(year) / sizeof(year[0]);
	SelectSortInt(year, len);
	PrintfArr(year, len);
}


void CommArrSort(int(* callbk)(void*,void *),void *pArr,int len,int eleSize) {
	char *temp = (char*)malloc(eleSize);
	for (int i = 0; i < len; i++)
	{
		int min = i;					//
		for (int j = 1+i; j < len; j++)
		{
			char *pMin = (char*)pArr + min * eleSize;
			char *pj = (char*)pArr + eleSize * j;
			if (callbk(pMin,pj)) {
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
void CallbkPrintfIntArr(void(* data)) {
	int* num = (int *)data;
	printf("%d ",*num);
}

typedef struct {
	char* pname;
	int age;
}SuperStar;

void CallbkPrintfStruArr(void(*data)) {
	SuperStar *star = data;
	printf("age=%d; name=%s\n", star->age,star->pname);
}

int CallbkSortStruArr(void* p1, void* p2) {
	SuperStar* s1 = p1;
	SuperStar* s2 = p2;
	if (s1->age > s2->age) {
		return 1;
	}
	else {
		return 0;
	}
}

void FuncCalled01() {
	int years[5] = {0};
	int len=sizeof(years)/sizeof(years[0]);
	printf("Enter %d element:\n",len);
	for (int i = 0; i < len; i++){
		scanf("%d", &years[i]);
	}
	printf("Sort before:");
	CommPrintfArr(CallbkPrintfIntArr, years, len, sizeof(years[0]));
	CommArrSort(CallbkSortIntArr, years, len, sizeof(years[0]));
	printf("\nSort after :");
	CommPrintfArr(CallbkPrintfIntArr, years, len, sizeof(int));

}

void FuncCalled02() {
	SuperStar struArr[] = {
		{"Messi",33},{"Bin",30},{"Zlatan",39},
		{"Xavi",40} ,{"Iniesta",36}
	};
	int struLen = sizeof(struArr) / sizeof(struArr[0]);
	int stEleSize = sizeof(struArr[0]);
	printf("struct before:\n");
	CommPrintfArr(CallbkPrintfStruArr, struArr, struLen, stEleSize);
	CommArrSort(CallbkSortStruArr, struArr, struLen, stEleSize);
	printf("\nstruct after :\n");
	CommPrintfArr(CallbkPrintfStruArr, struArr, struLen, stEleSize);
}

void main() {
	//Test01();
	//FuncCalled01();
	FuncCalled02();
}