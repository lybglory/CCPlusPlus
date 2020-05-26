#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkQueue.h"

//initialize
VLinkQue LinkQueInit(){ 
	struct StruLkQue *lkQue = malloc(sizeof(struct StruLkQue));
	if (lkQue==NULL) {
		return;
	}
	lkQue->head.next = NULL;
	lkQue->queCount = 0;
	lkQue->tail = &lkQue->head;//end to end
	return lkQue;
}

//link queue push
void PushLinkQue(VLinkQue vLkQue,void *pushData) {
	if (vLkQue==NULL||pushData==NULL) {
		return;
	}

	struct StruLkQue *lkQue = vLkQue;
	struct StruQueLknd *lkQueNewNode = pushData;

	//本质：tail insert
	lkQue->tail->next = lkQueNewNode;
	lkQueNewNode->next = NULL;
	lkQue->tail = lkQueNewNode;
	lkQue->queCount++;
}

//pop
void PopLinkQue(VLinkQue vLkQue){
	if (vLkQue == NULL) {
		return;
	}
	//本质，delete node of head
	struct StruLkQue *lkQue = vLkQue;
	struct StruQueLknd *popLkQueData = lkQue->head.next;
	//if just one node
	if (lkQue->queCount==1) {
		lkQue->head.next = NULL;
		lkQue->head.next = NULL;
		lkQue->tail = &lkQue->head;//end to end
		lkQue->queCount--;
		return;
	}

	lkQue->head.next = popLkQueData->next;
	lkQue->queCount--;
}

//return head
VLinkQue GetLinkQueHead(VLinkQue vLkQue){
	if (vLkQue == NULL) {
		return NULL;
	}
	//
	struct StruLkQue *lkQue = vLkQue;
	if (lkQue->queCount==0) {
		return NULL;
	}
	return lkQue->head.next;
}

//return tail
VLinkQue GetLinkQueTail(VLinkQue vLkQue) {
	if (vLkQue == NULL) {
		return NULL;
	}
	//
	struct StruLkQue *lkQue = vLkQue;
	if (lkQue->queCount == 0) {
		return NULL;
	}
	return lkQue->tail;
}

//return count of link queue
int GetLinkQueCount(VLinkQue vLkQue) {
	if (vLkQue == NULL) {
		return -1;
	}
	//
	struct StruLkQue *lkQue = vLkQue;

	return lkQue->queCount;
}
//
int LinkQueIsNULL(VLinkQue vLkQue) {
	if (vLkQue == NULL) {
		return -1;
	}
	//
	struct StruLkQue *lkQue = vLkQue;
	if (lkQue->queCount==0) {
		return 1;//return 1,link queue is null;
	}
	return 0;//return 0,is not null;
}
//
void DestroyLinkQue(VLinkQue vLkQue) {
	if (vLkQue == NULL) {
		return;
	}
	free(vLkQue);
	vLkQue = NULL;
}

void PrintStrutComm(VLinkQue vLkQue,void(*calbkPrintf)(void *)) {
	if (vLkQue ==NULL) {
		return;
	}

	struct StruLkQue *lkQue = vLkQue;
	struct StruQueLknd *lkndQueCurr = lkQue->head.next;
	for (int i = 0; i < lkQue->queCount; i++)
	{
		calbkPrintf(lkndQueCurr);
		lkndQueCurr = lkndQueCurr->next;
	}

}