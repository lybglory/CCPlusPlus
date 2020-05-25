#pragma once
//link node of queue
struct StruQueLknd {
	struct StruQueLknd *next;
};

//struct of queue
struct StruLkQue {
	struct StruQueLknd head;
	int queCount;
	struct StruQueLknd *tail;//Convenient to do end insert
};
typedef void *VLinkQue;
//initialize
extern VLinkQue LinkQueInit();

//link queue push
extern void PushLinkQue(VLinkQue vLkQue, void *pushData);

//pop
extern void PopLinkQue(VLinkQue vLkQue);

//return head
extern VLinkQue GetLinkQueHead(VLinkQue vLkQue);

//return tail
VLinkQue GetLinkQueTail();

//return count of link queue
extern int GetLinkQueCount();
//
extern int LinkQueIsNULL();
//
extern void DestroyLinkQue();