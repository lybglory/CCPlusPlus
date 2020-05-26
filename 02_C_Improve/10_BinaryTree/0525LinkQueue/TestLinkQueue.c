#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkQueue.h"
typedef struct {
	void *pAddr;
	char name[10];
	int age;
}Person;

void CalbkPrintfStru(void *data) {
	Person* p = data;
	printf("%s	%d\n",p->name,p->age);
}

void TestLkQueue() {
	Person p1 = { NULL,"Messi",33 };
	Person p2 = { NULL,"Bin",18 };
	Person p3 = { NULL,"Mei",18 };
	Person p4 = { NULL,"Soup",1 };
	Person p5 = { NULL,"Kuen",29 };

	//1.Initial
	VLinkQue vlkQue = LinkQueInit();

	//2.Push
	PushLinkQue(vlkQue, &p1);
	PushLinkQue(vlkQue, &p2);
	PushLinkQue(vlkQue, &p3);
	PushLinkQue(vlkQue, &p4);
	PushLinkQue(vlkQue, &p5);
	printf("count of link queue=%d\n",GetLinkQueCount(vlkQue));
	PrintStrutComm(vlkQue, CalbkPrintfStru);
	
	printf("\n==LinkQueue enqueue==\n");
	while (LinkQueIsNULL(vlkQue) == 0) {
		Person *pLkQueHead = GetLinkQueHead(vlkQue);
		printf("head	%s	%d	", pLkQueHead->name, pLkQueHead->age);

		Person *pLkQueTail = GetLinkQueTail(vlkQue);
		printf("tail	%s	%d\n", pLkQueTail->name, pLkQueTail->age);
		PopLinkQue(vlkQue);
	}
	printf("count of link queue=%d\n", GetLinkQueCount(vlkQue));
	DestroyLinkQue(vlkQue);
}
void main() {
	TestLkQueue();
}