#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArr.h"
#include "SeqQueue.h"

typedef struct  {
	char name[10];
	int age;
}Person;
void calbkPrintfPr(void *data) {
	Person *p = data;
	printf("%s	%d\n",p->name,p->age);
}

void TestDyArr() {
	Person p1 = { "Bin",18 };
	Person p2 = { "Mei",18 };
	Person p3 = { "Sweet",1 };
	Person p4 = { "Pei",29 };
	Person p5 = { "Kuen",18 };

	struct DyArrStru *dyArr = DyArrInit(3);
	printf("capacity=%d	count=%d\n",dyArr->arrCapacity,dyArr->arrCount);
	InsertArr(dyArr, 0, &p1);	//Bin
	InsertArr(dyArr, 1, &p2);	//Bin Mei
	InsertArr(dyArr, 0, &p3);	//Sweet Bin Mei
	InsertArr(dyArr, 2, &p4);	//Sweet Bin Pei Mei
	InsertArr(dyArr, 4, &p5);	//Sweet Bin Pei Mei Kuen
	PrintDyArrComm(dyArr, calbkPrintfPr);
	printf("capacity=%d	count=%d\n", dyArr->arrCapacity, dyArr->arrCount);

}

VdSeqQue SeqQueueInit() {					//queue init
	struct DyArrStru *seqQue = DyArrInit(3);
	return seqQue;
}

void Enqueue(VdSeqQue vdSeqQue, void *pushData) {
	if (vdSeqQue==NULL || pushData==NULL) {
		return;
	}
	struct DyArrStru* seqQue = vdSeqQue;
	if (seqQue->arrCount==queueMax) {
		return;
	}

	InsertArr(seqQue, seqQue->arrCount, pushData);
}

void Dequeue(VdSeqQue vdSeqQue) {
	if (vdSeqQue == NULL) {
		return;
	}
	struct DyArrStru *seqQue = vdSeqQue;
	if (seqQue->arrCount == 0) {
		return;
	}
	//first in first out,head remove
	RemoveDyArrByPos(seqQue,0);
}

void *GetHeadQueue(VdSeqQue vdSeqQue) {
	if (vdSeqQue == NULL) {
		return;
	}
	struct DyArrStru *seqQue = vdSeqQue;
	return seqQue->dyptAddr[0];
}

void *GetTailQueue(VdSeqQue vdSeqQue) {
	if (vdSeqQue == NULL) {
		return;
	}
	struct DyArrStru *seqQue = vdSeqQue;
	return seqQue->dyptAddr[seqQue->arrCount-1];
}

int GetQueueCount(VdSeqQue vdSeqQue) {
	if (vdSeqQue == NULL) {
		return;
	}
	struct DyArrStru *seqQue = vdSeqQue;
	return seqQue->arrCount;
}

int GetQueIsNULL(VdSeqQue vdSeqQue) {
	if (vdSeqQue == NULL) {
		return -1;
	}
	struct DyArrStru *seqQue = vdSeqQue;
	if (seqQue->arrCount==0) {
		return 1;			//NULL,return 1
	}
	return 0;				//not null,return 0
}

void DestoryQueue(VdSeqQue vdSeqQue) {
	if (vdSeqQue == NULL) {
		return;
	}
	ClearDyArr(vdSeqQue);
}



void main() {
	//TestDyArr();
}