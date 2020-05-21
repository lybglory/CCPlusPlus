#pragma once
struct DyArrStru {
	void **dyptAddr;
	int arrCapacity;
	int arrCount;
};

//
extern struct DyArrStru *DyArrInit(int capacity);

//
extern void InsertArr(struct DyArrStru *dyArr, int pos, void *insertData);

//
extern void PrintDyArrComm(struct DyArrStru *dyArr, void( *callbkFunc)(void *));

//
extern void RemoveDyArrByPos(struct DyArrStru *dyArr, int pos);

//
extern void RemoveDyArrByValue(struct DyArrStru *dyArr, void *data, int( *calbkCompare)(void *, void *));

//
extern void ClearDyArr(struct DyArrStru *dyArr);