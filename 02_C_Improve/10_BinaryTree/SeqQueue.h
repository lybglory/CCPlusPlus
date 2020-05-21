#pragma once
typedef void *VdSeqQue;

extern VdSeqQue SeqQueueInit();		//queue init

extern void PushQueue(VdSeqQue vdSeqQue,void *pushData);			//push

extern void PopQueue(VdSeqQue vdSeqQue);				//pop

extern void *GetHeadQueue(VdSeqQue vdSeqQue);		//head of queue

extern void *GetTailQueue(VdSeqQue vdSeqQue);		//tail queque

extern int GetQueueCount(VdSeqQue vdSeqQue);		//get count

extern int GetQueIsNULL(VdSeqQue vdSeqQue);			//is null?

extern void DestoryQueue(VdSeqQue vdSeqQue);		//destory
