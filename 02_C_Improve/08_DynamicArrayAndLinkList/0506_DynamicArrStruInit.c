#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  {
	char* name;
	int age;
}Person;
struct DyArrStru {
	void **dyptAddr;	//address
	int arrCapacity;	//initial capacity
	int arrCount;		//array count
};


struct DyArrStru *DyArrInit(int capacity) {
	if (capacity<=0) {
		return NULL;
	}
	struct DyArrStru *dyArr = (struct DyArrStru *)malloc(sizeof(struct DyArrStru));
	if (dyArr==NULL) {
		return NULL;
		perror("malloc error");
	}
	dyArr->dyptAddr=(void **)malloc(sizeof(void *)*capacity);
	dyArr->arrCapacity = capacity;	//initial capacity
	dyArr->arrCount = 0;			//initial arrayCount
}

void InsertArr(struct DyArrStru *dyArr,int pos,void *insertData) {
	if (dyArr==NULL||insertData==NULL) {
		return;
		perror("malloc error");
	}
	if (pos<0||pos>dyArr->arrCount) {
		pos = dyArr->arrCount;		//tail insert
	}
	if (dyArr->arrCapacity==dyArr->arrCount) {
		//1.Calculate the size of the new memory space
		int newCapacity = dyArr->arrCapacity * 2;
		//2.malloc new space
		void **newDyptAddr = (void **)malloc(sizeof(void *)*newCapacity);
		//3.meme copy
		memcpy(newDyptAddr,dyArr->dyptAddr,sizeof(void *)*newCapacity);
		
		free(dyArr->arrCapacity);		//4.free original space
		dyArr->dyptAddr=newDyptAddr;	//5.change pointer
		dyArr->arrCapacity= newCapacity;//6.update capacity 
	}
	//insert
	for (int i = dyArr->arrCount-1; i >=pos ; i--)
	{	//����
		dyArr->dyptAddr[i + 1] = dyArr->dyptAddr[i];
	}
	//update position
	dyArr->dyptAddr[pos] = insertData;
	dyArr->arrCount++;

}

void PrintDyArrComm(struct DyArrStru* dyArr, void( *callbkFunc)(void *)) {
	if (dyArr==NULL) {
		return;
	}
	for (int i = 0; i < dyArr->arrCount; i++)
	{
		callbkFunc(dyArr->dyptAddr[i]);
	}
}

void CallbkDyPrint(void *data) {
	Person *pr = data;
	printf("name=%s; age=%d\n",pr->name,pr->age);
}

void DyArrInsertTest() {
	struct DyArrStru *dyArr =DyArrInit(3);
	Person p1 = { "Messi",33 };
	Person p2 = { "LvBu",35 };
	Person p3 = { "Bin",18 };
	Person p4 = { "Mei",18 };
	InsertArr(dyArr, 1, &p1);
	InsertArr(dyArr, 2, &p2);
	InsertArr(dyArr, 0, &p3);

	PrintDyArrComm(dyArr, CallbkDyPrint);
}

void main() {
	DyArrInsertTest();
}