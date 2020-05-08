#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArr.h"
typedef struct  {
	char* name;
	int age;
}Person;

int CalbkCompare(void *data1,void *data2) {
	Person *p1 = (Person *)data1;
	Person *p2 = (Person *)data2;
	if (strcmp(p1->name,p2->name)==0&&p1->age==p2->age) {
		return 1;
	}
	else {
		return 0;
	}
}

void CallbkDyPrint(void* data) {
	Person* pr = data;
	printf("%s;		%d\n", pr->name, pr->age);
}

void DyArrTest() {
	struct DyArrStru *dyArr =DyArrInit(3);
	Person p1 = { "Messi",33 };
	Person p2 = { "LvBu",35 };
	Person p3 = { "Bin",18 };
	Person p4 = { "Mei",18 };
	printf("before:		Capacity=%d	count=%d\n",dyArr->arrCapacity,dyArr->arrCount);
	InsertArr(dyArr, 1, &p1);
	InsertArr(dyArr, 2, &p2);
	InsertArr(dyArr, 0, &p3);
	InsertArr(dyArr, 0, &p4);
	//"Mei" "Bin" "Messi" "LvBu"
	PrintDyArrComm(dyArr, CallbkDyPrint);
	printf("after:		Capacity=%d	count=%d\n", dyArr->arrCapacity, dyArr->arrCount);

	//remove by position
	RemoveDyArrByPos(dyArr, 3);	//remove "LvBu"
	printf("\nremove by position:Capacity=%d	count=%d\n", dyArr->arrCapacity, dyArr->arrCount);
	PrintDyArrComm(dyArr, CallbkDyPrint);

	//remove by value
	Person pr = { "Messi",33 };
	RemoveDyArrByValue(dyArr,&pr,CalbkCompare);//remove "Messi"
	printf("\nremove by value:Capacity=%d	count=%d\n", dyArr->arrCapacity, dyArr->arrCount);
	PrintDyArrComm(dyArr, CallbkDyPrint);

	//clear dynamic array
	ClearDyArr(dyArr);
	dyArr = NULL;			//must be null
}

void main() {
	DyArrTest();
}