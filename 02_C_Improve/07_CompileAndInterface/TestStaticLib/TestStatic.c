#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintfAnyArr.h"
#pragma comment(lib,"./0430_StaticLib.lib")
void PrintfIntArr(void* data) {
	int* num = (int*)data;
	printf("%d\n", *num);
}
void main() {
	int years[] = {2020,2019,2018,2017,2016};
	int len = sizeof(years) / sizeof(sizeof(int));
	CommPrintfArr(PrintfIntArr,years,len,sizeof(int));
}