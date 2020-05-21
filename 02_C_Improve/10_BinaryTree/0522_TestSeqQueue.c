#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArr.h"
#include "SeqQueue.h"

typedef struct {
	char name[10];
	int age;
}Person;

void calbkPrintfPr(void* data) {
	Person* p = data;
	printf("%s	%d\n", p->name, p->age);
}

void TestDyArr() {
	Person p1 = { "Bin",18 };
	Person p2 = { "Mei",18 };
	Person p3 = { "Sweet",1 };
	Person p4 = { "Pei",29 };
	Person p5 = { "Kuen",18 };

	struct DyArrStru* dyArr = DyArrInit(3);
	printf("capacity=%d	count=%d\n", dyArr->arrCapacity, dyArr->arrCount);
	InsertArr(dyArr, 0, &p1);	//Bin
	InsertArr(dyArr, 1, &p2);	//Bin Mei
	InsertArr(dyArr, 0, &p3);	//Sweet Bin Mei
	InsertArr(dyArr, 2, &p4);	//Sweet Bin Pei Mei
	InsertArr(dyArr, 4, &p5);	//Sweet Bin Pei Mei Kuen
	PrintDyArrComm(dyArr, calbkPrintfPr);
	printf("capacity=%d	count=%d\n", dyArr->arrCapacity, dyArr->arrCount);

}

void TestSeqQue() {
	Person p1 = { "Bin",18 };
	Person p2 = { "Mei",18 };
	Person p3 = { "Sweet",1 };
	Person p4 = { "Pei",29 };
	Person p5 = { "Kuen",18 };

	VdSeqQue vdSeqQue = SeqQueueInit();

	Enqueue(vdSeqQue, &p1);
	Enqueue(vdSeqQue, &p2);
	Enqueue(vdSeqQue, &p3);
	Enqueue(vdSeqQue, &p4);
	Enqueue(vdSeqQue, &p5);

	printf("queue count= %d\n",GetQueueCount(vdSeqQue));

	PrintDyArrComm(vdSeqQue, calbkPrintfPr);
	printf("==enqueue==\n");
	while (GetQueIsNULL(vdSeqQue)==0) {
		Person* pQueHead = GetHeadQueue(vdSeqQue);
		printf("head	%s	%d	", pQueHead->name, pQueHead->age);

		Person *pQueTail = GetTailQueue(vdSeqQue);
		printf("tail	%s	%d\n", pQueTail->name, pQueTail->age);
		
		Dequeue(vdSeqQue);
	}
	printf("queue count= %d", GetQueueCount(vdSeqQue));
	DestoryQueue(vdSeqQue);
}

void main() {
	TestSeqQue();
}