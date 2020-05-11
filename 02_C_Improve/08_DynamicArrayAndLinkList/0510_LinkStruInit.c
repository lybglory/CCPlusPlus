#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LinkNode {
	void *data;					//data
	struct LinkNode *lkNext;	//pointer
};

struct Dylkls{
	struct LinkNode *lkHead;	//link head
	int lkCount;				//link count
};
struct Person {
	char *name;
	int age;
};
void *DylkArrInit() {
	struct Dylkls *dylk = (struct Dylkls *)malloc(sizeof(struct Dylkls));
	if (dylk==NULL) {
		return;
	}
	//Data domains are not maintained
	dylk->lkHead->lkNext = NULL;
	dylk->lkCount = 0;
	return dylk;
}

void InsertDylk(void *v_dylk,void *data,int pos) {
	if (v_dylk==NULL||data==NULL) {
		return;
	}
	struct Dylkls *tmpDylkArr=v_dylk;
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

void IterateDylkComm(void *v_dylk,void( *calbkPrStru)(void *)) {
	if (v_dylk==NULL) {
		return;
	}
	struct Dylkls *dylk = v_dylk;
	struct LinkNode *lknd = dylk->lkHead->lkNext;
	for (int i = 0; i < dylk->lkCount; i++)
	{
		calbkPrStru(lknd->data);//callback
		lknd = lknd->lkNext;	//move pointer
	}
}
void CalbkPrStru(void *data) {
	struct Person *pr = data;
	printf("%s  %d\n",pr->name,pr->age);
}
void main() {

}