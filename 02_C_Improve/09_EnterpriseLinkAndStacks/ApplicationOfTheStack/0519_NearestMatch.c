#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SequenceStack.h"
typedef struct  {
	char name[10];
	int age;
}Person;

void TestSeqStk() {
	Person p1 = { "Soup",1 };
	Person p2 = { "Mei",18 };
	Person p3 = { "Bin",18 };
	Person p4 = { "Kuen",29 };
	Person p5 = { "Wear",29 };

	VdSequenStk vdSeqStk = SeqStkInit();
	PushSeqStk(vdSeqStk, &p1);
	PushSeqStk(vdSeqStk, &p2);
	PushSeqStk(vdSeqStk, &p3);
	PushSeqStk(vdSeqStk, &p4);
	PushSeqStk(vdSeqStk, &p5);
	printf("Push after count=%d\n\n",GetSeqStkCount(vdSeqStk));

	while (SeqStkIsNULL(vdSeqStk)==0) {
		Person *pTop = GetSeqTopStk(vdSeqStk);
		printf("%s	%d\n",pTop->name,pTop->age);
		PopSeqStk(vdSeqStk);					//pop stack;
	}
	printf("Pop after count=%d\n\n", GetSeqStkCount(vdSeqStk));

	DestorySeqStk(vdSeqStk);

}
void main() {
	TestSeqStk();
}