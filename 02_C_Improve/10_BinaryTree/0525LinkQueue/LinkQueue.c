#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkQueue.h"
//initialize
VLinkQue QueLkInit(){ 
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
void PushLinkQue(){ }

//pop
void PopLinkQue(){ }

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