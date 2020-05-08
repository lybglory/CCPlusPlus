#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArr.h"

struct DyArrStru* DyArrInit(int capacity) {
	if (capacity <= 0) {
		return NULL;
	}
	struct DyArrStru* dyArr = (struct DyArrStru*)malloc(sizeof(struct DyArrStru));
	if (dyArr == NULL) {
		return NULL;
		perror("malloc error");
	}
	dyArr->dyptAddr = (void**)malloc(sizeof(void*) * capacity);
	dyArr->arrCapacity = capacity;	//initial capacity
	dyArr->arrCount = 0;			//initial arrayCount
}

void InsertArr(struct DyArrStru* dyArr, int pos, void* insertData) {
	if (dyArr == NULL || insertData == NULL) {
		return;
		perror("malloc error");
	}
	if (pos<0 || pos>dyArr->arrCount) {
		pos = dyArr->arrCount;		//tail insert
	}
	if (dyArr->arrCapacity == dyArr->arrCount) {
		//1.Calculate the size of the new memory space
		int newCapacity = dyArr->arrCapacity * 2;
		//2.malloc new space
		void** newDyptAddr = (void**)malloc(sizeof(void*) * newCapacity);
		//3.meme copy
		memcpy(newDyptAddr, dyArr->dyptAddr, sizeof(void*) * dyArr->arrCapacity);
		free(dyArr->dyptAddr);			//4.free original space
		dyArr->dyptAddr = newDyptAddr;	//5.change pointer
		dyArr->arrCapacity = newCapacity;//6.update capacity 
	}
	//insert
	for (int i = dyArr->arrCount - 1; i >= pos; i--)
	{	//µ¹Ðð
		dyArr->dyptAddr[i + 1] = dyArr->dyptAddr[i];
	}
	//update position
	dyArr->dyptAddr[pos] = insertData;
	dyArr->arrCount++;

}

void PrintDyArrComm(struct DyArrStru* dyArr, void(*callbkFunc)(void*)) {
	if (dyArr == NULL) {
		printf("dyArr==NULL");
		return;
	}
	for (int i = 0; i < dyArr->arrCount; i++)
	{
		callbkFunc(dyArr->dyptAddr[i]);
	}
}

void RemoveDyArrByPos(struct DyArrStru* dyArr, int pos) {
	//pos max=arrCount-1,exist.so > is not exist
	if (dyArr == NULL || pos <= 0 || pos > dyArr->arrCount - 1) {
		return;
	}

	for (int i = pos; i < dyArr->arrCount; i++)
	{	//The latter position moves forward
		dyArr->dyptAddr[i] = dyArr->dyptAddr[i + 1];
	}
	dyArr->arrCount--;//change element count
}

void RemoveDyArrByValue(struct DyArrStru* dyArr, void* data, int(*calbkCompare)(void*, void*)) {
	if (dyArr == NULL || data == NULL) {
		return;
	}
	for (int i = 0; i < dyArr->arrCount; i++)
	{
		if (calbkCompare(dyArr->dyptAddr[i], data) == 1) {
			RemoveDyArrByPos(dyArr, i);
			break;
		}
	}
}

void ClearDyArr(struct DyArrStru* dyArr) {
	if (dyArr == NULL) {
		return;
	}
	if (dyArr->dyptAddr != NULL) {
		free(dyArr->dyptAddr);
		dyArr->dyptAddr == NULL;
	}
	free(dyArr);
	dyArr = NULL;
}
