#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArr.h"

struct DyArrStru *DyArrInit(int capacity) {
	if (capacity<0) {
		return;
	}
	struct DyArrStru *dyArr = (struct DyArrStru *)malloc(sizeof(struct DyArrStru));
	if (NULL==dyArr) {
		return;
	}
	dyArr->dyptAddr = (void **)malloc(sizeof(void *)* capacity);
	dyArr->arrCapacity = capacity;
	dyArr->arrCount = 0;
	return dyArr;
}

void InsertArr(struct DyArrStru *dyArr, int pos, void* insertData) {
	if (dyArr==NULL || insertData==NULL) {
		return;
	}
	if (pos<0||pos>dyArr->arrCount-1) {
		pos = dyArr->arrCount;
	}
	
	if (dyArr->arrCapacity==dyArr->arrCount) {
		int newCapacity = dyArr->arrCapacity * 2;
		void **newDyptAddr = (void **)malloc(sizeof(void*)* newCapacity);
		memcpy(newDyptAddr,dyArr->dyptAddr,sizeof(void *)*dyArr->arrCapacity);
		free(dyArr->dyptAddr);
	}

	//clearing a space for insertdata
	for (int i = dyArr->arrCount-1; i >= pos; i++)
	{
		dyArr->dyptAddr[i+1] = dyArr->dyptAddr[i];
	}
	dyArr->dyptAddr[pos] = insertData;
	dyArr->arrCount++;
}

void PrintDyArrComm(struct DyArrStru *dyArr, void(*callbkFunc)(void*)) {
	if (dyArr == NULL) {
		return;
	}
	for (int i = 0; i < dyArr->arrCount; i++)
	{
		callbkFunc(dyArr->dyptAddr[i]);
	}
}

void RemoveDyArrByPos(struct DyArrStru *dyArr, int pos) {
	if (dyArr==NULL|| pos>dyArr->arrCount-1) {
		return;
	}


	for (int i = pos; i < dyArr->arrCount; i++)
	{
		dyArr->dyptAddr[i] = dyArr->dyptAddr[i + 1];
	}

	dyArr->arrCount--;
}