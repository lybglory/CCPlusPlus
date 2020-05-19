#pragma once
#define maxSize 1024
typedef void *VdSequenStk;

struct StruSequenceStk {
	void *dataArr[maxSize];
	int SeqCount;
};

//initialize
extern VdSequenStk SeqStkInit();

//Push stack
extern void PushSeqStk(VdSequenStk vdSeqStk, void* pushData);

//Pop stack
extern void PopSeqStk(VdSequenStk vdSeqStk);

//Get top stack
extern VdSequenStk GetSeqTopStk(VdSequenStk vdSeqStk);

//get count
extern int GetSeqStkCount(VdSequenStk vdSeqStk);

//is null?
extern int SeqStkIsNULL(VdSequenStk vdSeqStk);

//destory
extern void DestorySeqStk(VdSequenStk vdSeqStk);