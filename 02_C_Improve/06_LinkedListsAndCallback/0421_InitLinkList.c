#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InitLinkList.h"
extern struct Linkls *InitLinkls() {
	struct Linkls *lkHead = (struct Linkls*)malloc(sizeof(struct Linkls));
	if (lkHead ==NULL) {
		perror("Linklist is null");
		return;
	}
	lkHead->year = -1;//head node
	lkHead->lkNext = NULL;
	int val = -1;
	struct Linkls *lkTail = lkHead;
	while (1)
	{
		printf("Please insert data. Enter -1 to indicate the end of the insert:\n");
		scanf("%d",&val);
		if (val==-1) {
			break;
		}

		struct Linkls *newLinkls = (struct Linkls*)malloc(sizeof(struct Linkls));
		newLinkls->year= val;
		newLinkls->lkNext = NULL;
		lkTail->lkNext = newLinkls;
		lkTail = newLinkls;
	}
	return lkHead;
}

extern void ForeachLink(struct Linkls *lkls) {
	if (lkls==NULL) {
		return;
	}
	struct Linkls *currpLink = lkls->lkNext;
	while (currpLink !=NULL) {
		printf("link:year=%d\n",currpLink->year);
		currpLink = currpLink->lkNext;
	}


}

extern void FreePlink(struct Linkls *lkls) {
	if (lkls != NULL) {
		free(lkls);
		lkls = NULL;
	}
<<<<<<< HEAD

	struct Linkls *lkCurr = lkls->lkNext;
	struct Linkls *lkPre = lkls;
	while (lkCurr!=NULL) {
		if (lkCurr->year == insertPos) {
			break;
		}
		lkPre = lkCurr;				//记录前一个节点
		lkCurr = lkCurr->lkNext;	//向后移动
	}
	struct Linkls *newNode = (struct Linkls*)malloc(sizeof(struct Linkls));
	newNode->year = insertVal;
	newNode->lkNext = NULL;

	newNode->lkNext = lkCurr;
	lkPre->lkNext = newNode;
=======
>>>>>>> parent of 1142006... link list insert
}

extern void DeletelkNode(struct Linkls *lkhead,int delVal) {
	if (lkhead==NULL) {
		return;
	}
	struct Linkls *lkpre = lkhead;
	struct Linkls *lkCurr = lkhead->lkNext;
	while (lkCurr != NULL)
	{	//find need delete，break
		if (lkCurr->year==delVal) {
			break;
		}
		//not find,move pointer
		lkpre = lkCurr;				//记录前一个节点
		lkCurr = lkCurr->lkNext;	//向后移动
	}
	if (lkCurr==NULL) {
		return;
	}
	//
	lkpre->lkNext = lkCurr->lkNext;//当前节点下一个指针域作为前一个节点
	free(lkCurr); 
	lkCurr = NULL;
}
extern void ClearLink(struct Linkls *lkHead) {
	if (lkHead==NULL) {
		return;
	}
	struct Linkls *lkCurr = lkHead->lkNext;
	while (lkCurr!=NULL)
	{	//if free lkCurr at first,it will cause a program exception
		struct Linkls *lkTemp = lkCurr->lkNext;
		free(lkCurr);
		lkCurr = lkTemp;
	}
	//head assign NULL
	lkHead->lkNext = NULL;
}

extern void DestoryLink(struct Linkls *lkHead) {
	if (lkHead==NULL) {
		return;
	}
	ClearLink(lkHead);
	free(lkHead);
	lkHead = NULL;
}

extern void ReverseLink(struct Linkls* lkHead) {
	if (lkHead == NULL) {
		return;
	}
	struct Linkls *ndCurr = lkHead->lkNext;
	struct Linkls *ndPre = NULL;
	struct Linkls *ndNext = NULL;
	while (ndCurr!=NULL)
	{
		ndNext = ndCurr->lkNext;
		//change point
		ndCurr->lkNext=ndPre;
		//move point
		ndPre = ndCurr;
		ndCurr = ndNext;
	}
	//
	lkHead->lkNext = ndPre;
}

extern int CountLinks(struct Linkls* lkHead) {
	if (lkHead == NULL) {
		return -1;
	}
	struct Linkls* ndCurr = lkHead->lkNext;
	int count = 0;
	while (ndCurr != NULL)
	{
		count++;
		ndCurr = ndCurr->lkNext;
	}
	return count;
}