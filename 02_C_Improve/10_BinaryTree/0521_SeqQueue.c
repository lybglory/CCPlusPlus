#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArr.h"
#include "SeqQueue.h"

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