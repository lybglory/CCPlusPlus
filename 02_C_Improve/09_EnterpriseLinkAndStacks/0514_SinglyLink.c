#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//node just record pointer arear
struct Linknd {
	struct Linknd *lkndNext;
};

struct Linkls {
	struct Linknd lklsHead;
	int lkndCount;
};


typedef struct {
	int *pAddr;	//Any four-byte data type is ok
	char *name;
	int age;

}PersonInfo;
//void * alias
typedef void *v_etpLink;

v_etpLink InitEnterpriseLinkls() {
	struct Linkls *lkls = malloc(sizeof(struct Linkls));
	if (NULL==lkls) {
		perror("malloc error");
		return;
	}
	lkls->lkndCount = 0;
	lkls->lklsHead.lkndNext = NULL;
	return lkls;
}

void InsertLknd(v_etpLink v_lkls,void *insertData,int pos) {
	if (v_lkls==NULL||insertData==NULL) {
		return;
	}
	struct Linkls *lkls = v_lkls;
	struct Linknd *inSertNd = insertData;
	struct Linknd *lkndCurr = &lkls->lklsHead;

	//max position=lkndCount-1
	if (pos<0|| pos>lkls->lkndCount-1) {
		pos = lkls->lkndCount;
	}
	//find precursor node
	for (int i = 0; i < pos; i++)
	{
		lkndCurr = lkndCurr->lkndNext;
	}
	inSertNd->lkndNext = lkndCurr->lkndNext;
	lkndCurr->lkndNext = inSertNd;
	lkls->lkndCount++;
}

void TraversalLinkls(v_etpLink v_lkls, void(* calbk)(void *)) {
	if (v_lkls==NULL) {
		return;
	}
	struct Linkls *lkls= v_lkls;
	struct Linknd *lkndCurr = lkls->lklsHead.lkndNext;
	for (int i = 0; i < lkls->lkndCount; i++)
	{
		calbk(lkndCurr);
		lkndCurr = lkndCurr->lkndNext;
	}
}

void CalbkPrinPerson(void *data) {
	PersonInfo *pData = data;
	printf("%s	%d\n",pData->name,pData->age);
}

void RemoveLinkNd(v_etpLink v_lkls,int pos) {
	if (NULL == v_lkls) {
		return;
	}
	struct Linkls *lkls= v_lkls;
	if (pos<0||pos>lkls->lkndCount-1) {	//Invalid position
		return;		
	}

	struct Linknd *lkndCurr = &lkls->lklsHead;
	for (int i = 0; i < pos; i++)		//find precursor node
	{
		lkndCurr = lkndCurr->lkndNext;
	}
	struct Linknd *lkndDel = lkndCurr->lkndNext;
	lkndCurr->lkndNext = lkndDel->lkndNext;
	lkls->lkndCount--;

}

void TestEtpLinkls() {
	PersonInfo p1 = {NULL,"Soup",1};
	PersonInfo p2 = { NULL,"Bin",18 };
	PersonInfo p3 = { NULL,"Mei",16 };
	PersonInfo p4 = { NULL,"Chan",15 };
	PersonInfo p5 = { NULL,"Juan",29 };
	v_etpLink v_lkls = InitEnterpriseLinkls();
	InsertLknd(v_lkls, &p1,3);	//Soup
	InsertLknd(v_lkls, &p2, 0);	//Bin Soup
	InsertLknd(v_lkls, &p3, 1);	//Bin Mei Soup
	InsertLknd(v_lkls, &p4, 2);	//Bin Mei Chan Soup
	InsertLknd(v_lkls, &p5, 0);	//Juan Bin Mei Chan Soup
	TraversalLinkls(v_lkls,CalbkPrinPerson);

	printf("Remove by pos 0\n");
	RemoveLinkNd(v_lkls,0);
	TraversalLinkls(v_lkls, CalbkPrinPerson);
}
void main() {
	TestEtpLinkls();
}