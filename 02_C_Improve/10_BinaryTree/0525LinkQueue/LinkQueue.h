#pragma once
//link node of queue
struct StruQueLknd {
	struct StruQueLknd *queLkndNext;
};

//struct of queue
struct StruLkQue {
	struct StruQueLknd queLklsHead;
	int queCount;
	struct StruQueLknd *queLklsTail;//Convenient to do end insert
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

int LinkQueIsNULL();

void DestroyLinkQue();