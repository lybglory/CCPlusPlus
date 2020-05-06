#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct DyArrStru {
	void **dypointer;	//address
	int arrCapacity;
	int arrSize;
};

struct DyArrStru *DyArrInit(int capacity) {
	if (capacity<=0) {
		return;
	}

	struct DyArrStru *dyArr = (struct DyArrStru*)malloc(sizeof(struct DyArrStru));
	if (dyArr==NULL) {
		perror("malloc error!");
		return;
	}
	dyArr->dypointer = (void **)malloc(sizeof(void *)*capacity);
	dyArr->arrCapacity = capacity;
	dyArr->arrSize = 0;
	return dyArr;

}
void main() {

}