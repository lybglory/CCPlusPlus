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
VLinkQue QueLkInit();

//link queue push
void PushLinkQue();

//pop
void PopLinkQue();

//return head
VLinkQue GetLinkQueHead();

//return tail
VLinkQue GetLinkQueTail();

//return count of link queue
int GetLinkQueCount();
//
int LinkQueIsNULL();
//
void DestroyLinkQue();