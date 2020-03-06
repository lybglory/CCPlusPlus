#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//自定义头文件用双引
#include "MallocCase.h"
void main() {
	printf("Please enter the total number of elements:");
	int num;
	scanf("%d", &num);
	int *pNum = NULL;	
	printf("main1：pNum=%x\n", &pNum);
	SetMallocElem(&pNum,num);
	
	printf("main2：pNum=%x\n",&pNum);
	PrintfMallocElem(pNum,num);
	MallocCompare(pNum,num);
	PrintfMallocElem(pNum, num);
	if (pNum!=NULL) {
		free(pNum);
		pNum = NULL;
	}
}