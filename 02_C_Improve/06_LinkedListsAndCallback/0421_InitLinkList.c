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
}
