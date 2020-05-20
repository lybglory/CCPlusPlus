#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SequenceStack.h"

//initialize
VdSequenStk SeqStkInit() {
	struct StruSequenceStk *seqStk = malloc(sizeof(struct StruSequenceStk));
	if (NULL==seqStk) {
		return;
	}

	memset(seqStk->dataArr,0,sizeof(void *)* maxSize);
	seqStk->SeqCount = 0;
	return seqStk;
}


void PushSeqStk(VdSequenStk vdSeqStk,void *pushData) {	//Push stack
	if (vdSeqStk==NULL||pushData==NULL) {
		return;
	}
	//sequence push
	struct StruSequenceStk *seqStk = vdSeqStk;
	if (seqStk->SeqCount==maxSize) {
		return;								//stack is full;
	}

	seqStk->dataArr[seqStk->SeqCount] = pushData;
	seqStk->SeqCount++;
}

void PopSeqStk(VdSequenStk vdSeqStk) {		//pop stack
	if (vdSeqStk == NULL ) {
		return;
	}
	//sequence push
	struct StruSequenceStk *seqStk = vdSeqStk;
	if (seqStk->SeqCount==0) {
		return;
	}
	seqStk->dataArr[seqStk->SeqCount-1] = NULL;
	seqStk->SeqCount--;
}

void *GetSeqTopStk(VdSequenStk vdSeqStk) {		//get top stack
	if (vdSeqStk == NULL) {
		return;
	}
	//sequence push
	struct StruSequenceStk *seqStk = vdSeqStk;
	if (seqStk->SeqCount == 0) {
		return NULL;
	}

	return seqStk->dataArr[seqStk->SeqCount - 1];
}

int GetSeqStkCount(VdSequenStk vdSeqStk) {		//get top stack
	if (vdSeqStk == NULL) {
		return;
	}
	//sequence push
	struct StruSequenceStk *seqStk = vdSeqStk;
	return seqStk->SeqCount;
}

int SeqStkIsNULL(VdSequenStk vdSeqStk) {		//get top stack
	if (vdSeqStk == NULL) {
		return -1;
	}
	//sequence push
	struct StruSequenceStk *seqStk = vdSeqStk;
	if (seqStk->SeqCount==0) {
		return 1;				//stack is null,return 1,true;
	}
	return 0;					//stack is not null,return 0, false;
}

void DestorySeqStk(VdSequenStk vdSeqStk) {		//Destory
	if (vdSeqStk == NULL) {
		return;
	}
	free(vdSeqStk);
	vdSeqStk = NULL;
}