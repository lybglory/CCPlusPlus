#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LinkNode {
	void *data;					//data
	struct LinkNode *lkNext;	//pointer
};

struct DyLinkArr{
	struct LinkNode *lkHead;	//link head
	int lkCount;				//link count
};

struct DyLinkArr *DylkArrInit() {
	struct DyLinkArr *dylkArr = (struct DyLinkArr *)malloc(sizeof(struct DyLinkArr));
	if (dylkArr==NULL) {
		return;
	}
	//Data domains are not maintained
	dylkArr->lkHead->lkNext = NULL;
	dylkArr->lkCount = 0;
	return dylkArr;
}


void main() {

}