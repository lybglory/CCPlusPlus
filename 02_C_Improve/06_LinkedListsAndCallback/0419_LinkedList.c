#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void main() {
	StaticLinked();
}