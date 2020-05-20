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

int GetLRBracket(char chr) {
	if (chr=='(') {
		return 9;
	}
	else if (chr==')') {
		return 0;
	}
	else
	{
		return -1;
	}
}

void ShowErrorMsg(char *arith,char *msg,char *chr) {
	printf("error:%s\n",msg);
	printf("%s\n",arith);
	int chrPos =  chr-arith;
	for (int i = 0; i < chrPos; i++)
	{
		printf(" ");
	}
	printf("^\n");
}
void StkMatch() {
	char *arithmetic= "2020/(5/20)-(21*50)+(3))";
	char *p = arithmetic;
	VdSequenStk vdSeqStk = SeqStkInit();
	while (*p !='\0')
	{	//left bracket,return 9.Push
		if (GetLRBracket(*p) == 9) {
			PushSeqStk(vdSeqStk, *p);
		}
		//right bracket,return 0.Pop
		if (GetLRBracket(*p)==0) {
			if (GetSeqStkCount(vdSeqStk) > 0) {
				PopSeqStk(vdSeqStk);
			}
			else
			{
				ShowErrorMsg(arithmetic, "right bracket matching failed!", p);//is not *p
				break;
			}
		}
		p++;
	}//while_end

	
}//func_end

void main() {
	//TestSeqStk();
	StkMatch();
}