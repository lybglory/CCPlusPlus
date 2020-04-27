#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person {
	char* name;
	int age;
};

//Format:return value(variable name)(formal parameter type)
void CallbackArr(void(* pFunc)(void *),void(* data),int length,int eleSize) {
	char *pArr = data;
	for (int i = 0; i < length; i++)
	{
		char *tempAddr = pArr +eleSize * i;
		pFunc(tempAddr);
	}
}
void PrintfIntArr(void(* data)) {
	int *num = data;
	printf("IntArr:%d\n",*num);
}

void main() {
	int yearArr[5] = {2020,2019,2018,2017,2016};
	int yearLeng = sizeof(yearArr) / sizeof(yearArr[0]);
	int eleSize = sizeof(yearArr[0]);
	CallbackArr(PrintfIntArr,yearArr, yearLeng, eleSize);
}