#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//自定义头文件用双引
#include "MallocCase.h"
void main_08_02() {
	printf("Please enter the total number of elements:");
	int num;
	scanf("%d", &num);
	int *pNum = NULL;	
	printf("main-1：&pNum=%x; pNum=%x\n", &pNum, pNum);
	//根据元素个数申请堆空间并设置每个元素的内容
	SetMallocElem(&pNum,num);
	
	printf("main-2：&pNum=%x; pNum=%x\n", &pNum, pNum);
	//输出每个元素
	PrintfMallocElem(pNum,num);
	//对元素进行排序
	MallocCompare(pNum,num);
	//排序后的元素
	PrintfMallocElem(pNum, num);
	if (pNum!=NULL) {
		free(pNum);
		pNum = NULL;
	}
}