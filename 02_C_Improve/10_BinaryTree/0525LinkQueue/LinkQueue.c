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
	lkQue->head.next = popLkQueData->next;
	lkQue->queCount++;
}

//return head
VLinkQue GetLinkQueHead(){}

//return tail
VLinkQue GetLinkQueTail(){ }

//return count of link queue
int GetLinkQueCount(){ }
//
int LinkQueIsNULL(){ }
//
void DestroyLinkQue(){ }

void main() {

}