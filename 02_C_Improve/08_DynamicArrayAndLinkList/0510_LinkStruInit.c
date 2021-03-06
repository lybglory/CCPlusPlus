#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LinkNode {
	void *data;					//data
	struct LinkNode *lkNext;	//pointer
};

struct Dylkls{
	struct LinkNode lkHead;	//link head
	int lkCount;				//link count
};
typedef struct {
	char *name;
	int age;
}Person;
void *DylkInit() {
	struct Dylkls *dylk = (struct Dylkls *)malloc(sizeof(struct Dylkls));
	if (dylk==NULL) {
		return;
	}
	//Data domains are not maintained
	dylk->lkHead.lkNext = NULL;
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

	struct LinkNode *ndCurr = &tmpDylkArr->lkHead;
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
	struct LinkNode *lknd = dylk->lkHead.lkNext;
	for (int i = 0; i < dylk->lkCount; i++)
	{
		calbkPrStru(lknd->data);//callback
		lknd = lknd->lkNext;	//move pointer
	}
}
void CalbkPrStru(void *data) {
	Person *pr = data;
	printf("%s		%d\n",pr->name,pr->age);
}

void DelDylkByPos(void *v_dylk,int pos) {
	if (v_dylk==NULL) {
		return;
	}
	struct Dylkls *dylk = (struct Dylkls*)v_dylk;
	if (pos<0||pos>dylk->lkCount-1) {
		return;
	}
	struct LinkNode *lkCurr = &dylk->lkHead;

	for (int i = 0; i < pos; i++)
	{
		lkCurr = lkCurr->lkNext;	//need delte
	}
	struct LinkNode *lkDel= lkCurr->lkNext;
	lkCurr->lkNext= lkDel->lkNext;
	free(lkDel);
	lkDel = NULL;

	dylk->lkCount--;
}

void DelDylkByValue(void *v_dylk, void *data,int(* calbkCompar)(void *,void *)) {
	if (v_dylk == NULL||data==NULL) {
		return;
	}
	struct Dylkls *dylk = (struct Dylkls*)v_dylk;
	struct LinkNode *ndCurr = dylk->lkHead.lkNext;
	struct LinkNode* ndPre = &dylk->lkHead;
	for (int i = 0; i < dylk->lkCount; i++)
	{
		if (calbkCompar(ndCurr->data,data)==1) {
			ndPre->lkNext = ndCurr->lkNext;
			free(ndCurr);
			ndCurr = NULL;
			dylk->lkCount--;
			break;
		}
		ndPre = ndCurr;
		ndCurr = ndCurr->lkNext;
	}
}
void CalbkCompareDylk(void *data1,void *data2) {
	Person *p1 = data1;
	Person *p2 = data2;
	if ((strcmp(p1->name,p2->name)==0)&&(p1->age==p2->age)) {
		return 1;
	}
	else {
		return 0;
	}
}

int GetlkCount(void *v_dylk) {
	if (v_dylk == NULL) {
		return;
	}
	struct Dylkls *dylk = (struct Dylkls*)v_dylk;
	return dylk->lkCount;
}

void ClearLkls(void *v_dylk) {
	if (v_dylk == NULL) {
		return;
	}
	struct Dylkls *dylk = (struct Dylkls*)v_dylk;
	struct LinkNode *ndCurr = dylk->lkHead.lkNext;
	for (int i = 0; i < dylk->lkCount; i++)
	{	
		struct LinkNode *tempCurrNext = ndCurr->lkNext;
		free(ndCurr);
		ndCurr = tempCurrNext;
	}
	dylk->lkHead.lkNext = NULL;
	dylk->lkCount = 0;
}

void DestroyLinkls(void *v_dylk) {
	if (v_dylk == NULL) {
		return;
	}
	ClearLkls(v_dylk);
	free(v_dylk);
	v_dylk = NULL;
}
void TestDylk() {
	Person p1 = { "Hua",30 };
	Person p2 = { "Bin",18 };
	Person p3 = { "Mei",18 };
	Person p4 = { "Pei",30 };
	Person p5 = { "Juan",29 };
	void *v_dylk=DylkInit();
	InsertDylk(v_dylk, &p1, 0);	//Hua
	InsertDylk(v_dylk, &p2, 0);//Bin Hua
	InsertDylk(v_dylk, &p3, 0);//Mei Bin Hua
	InsertDylk(v_dylk, &p4, 2);//Mei Bin Pei Hua
	InsertDylk(v_dylk, &p5, 1);//Mei Juan Bin Pei Hua
	IterateDylkComm(v_dylk, CalbkPrStru);
	printf("count=%d\n\n", GetlkCount(v_dylk));
	DelDylkByPos(v_dylk, 3);
	printf("##Delete by pos:Pei(index=3)##\n");
	IterateDylkComm(v_dylk, CalbkPrStru);
	printf("count=%d\n\n",GetlkCount(v_dylk));
	Person delData = { "Hua",30 };
	printf("##Delete by value:Hua##\n");
	DelDylkByValue(v_dylk,&delData, CalbkCompareDylk);
	IterateDylkComm(v_dylk, CalbkPrStru);
	printf("count=%d\n\n", GetlkCount(v_dylk));

	printf("##Clear link list##\n");
	ClearLkls(v_dylk);
	IterateDylkComm(v_dylk, CalbkPrStru);
	printf("count=%d\n\n", GetlkCount(v_dylk));

	//printf("##Destory link list##\n");
	DestroyLinkls(v_dylk);
	//printf("count=%d\n", GetlkCount(v_dylk));
}
void main() {
	TestDylk();
}