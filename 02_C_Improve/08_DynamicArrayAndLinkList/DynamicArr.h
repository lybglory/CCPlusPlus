#pragma once
struct DyArrStru {
	void** dyptAddr;	//address
	int arrCapacity;	//initial capacity
	int arrCount;		//array count
};
//Dynamic array initialization
extern struct DyArrStru *DyArrInit(int capacity);

//Insert data
extern void InsertArr(struct DyArrStru *dyArr, int pos, void *insertData);

//traverse element
extern void PrintDyArrComm(struct DyArrStru *dyArr, void(*callbkFunc)(void*));

//remove element by position
extern void RemoveDyArrByPos(struct DyArrStru *dyArr, int pos);

//remove element by value
extern void RemoveDyArrByValue(struct DyArrStru *dyArr, void *data, int( *calbkCompare)(void *, void *));

//clear dynamic array
extern void ClearDyArr(struct DyArrStru *dyArr);