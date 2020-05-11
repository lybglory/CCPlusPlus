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

void *DylkArrInit() {
	struct DyLinkArr *dylkArr = (struct DyLinkArr *)malloc(sizeof(struct DyLinkArr));
	if (dylkArr==NULL) {
		return;
	}
	//Data domains are not maintained
	dylkArr->lkHead->lkNext = NULL;
	dylkArr->lkCount = 0;
	return dylkArr;
}

void InsertDylk(void *dylkArr,void *data,int pos) {
	if (dylkArr==NULL||data==NULL) {
		return;
	}
	struct DyLinkArr *tmpDylkArr=dylkArr;
	if (pos<0|| pos>tmpDylkArr->lkCount) {	//invalid position
		pos = tmpDylkArr->lkCount;
	}

	struct LinkNode *ndCurr = tmpDylkArr->lkHead;
	//Create a temporary node by looping 
	//to find the location of the precursor node to be inserted
	for (int i = 0; i < pos; i++)
	{	//The subscript starts at 0
		ndCurr = ndCurr->lkNext;
	}
	struct LinkNode *newNode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->lkNext = NULL;

	//INSERT
	newNode->lkNext = ndCurr->lkNext;
	ndCurr->lkNext = newNode;
	tmpDylkArr->lkCount++;
}
void main() {

}