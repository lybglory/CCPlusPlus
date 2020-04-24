#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InitLinkList.h"
struct LinkNode {
	int year;
	struct LinkNode *linkNext;
};
void StaticLinked() {
	struct LinkNode node1 = { 2017,NULL };
	struct LinkNode node2 = { 2018,NULL };
	struct LinkNode node3 = { 2019,NULL };
	struct LinkNode node4 = { 2020,NULL };

	node1.linkNext = &node2;	//establish relationship
	node2.linkNext = &node3;
	node3.linkNext = &node4;
	
	struct LinkNode *pLink = &node1;
	while (pLink!=NULL)
	{
		printf("link:year=%d\n",pLink->year);
		pLink = pLink->linkNext;
	}
}

void DynamicLinked() {
	struct LinkNode *node1 = (struct LinkNode *)malloc(sizeof(struct LinkNode));
	struct LinkNode *node2 = (struct LinkNode *)malloc(sizeof(struct LinkNode));
	struct LinkNode *node3 = (struct LinkNode *)malloc(sizeof(struct LinkNode));
	struct LinkNode *node4 = (struct LinkNode *)malloc(sizeof(struct LinkNode));

	node1->year = 2017;
	node1->linkNext = node2;
	node2->year = 2018;
	node2->linkNext = node3;
	node3->year = 2019;
	node3->linkNext = node4;
	node4->year = 2020;
	node4->linkNext = NULL;	

	struct LinkNode *pLink = node1;
	while (pLink != NULL)
	{
		printf("Dynamic link:year=%d\n", pLink->year);
		pLink = pLink->linkNext;
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
}
void main() {
	//StaticLinked();
	//DynamicLinked();
	
	struct Linkls *lkls=InitLinkls();
	ForeachLink(lkls);
	InsertLink(lkls,2020,2004);
	printf("insert node:\n");
	ForeachLink(lkls);
	DeleteLink(lkls, 2004);
	printf("delete node:\n");
	ForeachLink(lkls);
	ClearLink(lkls);
	InsertLink(lkls, 2010, 2010);
	InsertLink(lkls, 2011, 2011);
	printf("clear link:\n");
	ForeachLink(lkls);

}