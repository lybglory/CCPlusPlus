#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stackMax 1024
struct OrderStack {
	void *dataArr[stackMax];
	int stackCount;
};

typedef void *v_Stack;

typedef struct{
	char name[10];
	int age;
}Person;

//initializae of stack
v_Stack StkInit() {
	struct OrderStack *stk = (struct OrderStack *)malloc(sizeof(struct OrderStack));
	if (stk==NULL) {
		return;
	}
	memset(stk->dataArr,0,sizeof(void *)* stackMax);
	stk->stackCount = 0;
	return stk;
}

//Push
void PushStack(v_Stack v_stk,void *pushData) {
	if (v_stk==NULL|| pushData==NULL) {
		return;
	}
	struct OrderStack *stk = v_stk;
	if (stk->stackCount==stackMax) {
		return;
	}
	//tail insert
	stk->dataArr[stk->stackCount] = pushData;
	stk->stackCount++;
}

//Pop
void PopStack(v_Stack v_stk) {
	if (v_stk == NULL) {
		return;
	}
	struct OrderStack* stk = v_stk;
	if (stk->stackCount == 0) {
		return;
	}
	//the last one to delete
	stk->dataArr[stk->stackCount - 1] = NULL;
	stk->stackCount--;
}

v_Stack GetTopStk(v_Stack v_stk) {
	if (v_stk == NULL) {
		return;
	}
	struct OrderStack* stk = v_stk;
	if (stk->stackCount == 0) {
		return;
	}
	return stk->dataArr[stk->stackCount - 1];
}

//
int GetStkCount(v_Stack v_stk) {
	if (v_stk == NULL) {
		return;
	}
	struct OrderStack *stk = v_stk;
	return stk->stackCount;
}

int IsStkNull(v_Stack v_stk) {
	if (v_stk == NULL) {
		return -1;
	}
	struct OrderStack *stk = v_stk;
	if (stk->stackCount==0) {
		return 1;           //stack is null
	}
	return 0;				//stack is not null
}

void DestoryStk(v_Stack v_stk) {
	if (v_stk == NULL) {
		return;
	}
	free(v_stk);
	v_stk = NULL;
}

void TestStk() {
	Person p1 = { "Messi",33 };
	Person p2 = { "Bingo",18 };
	Person p3 = { "Mei",18 };
	Person p4 = { "Soup",1 };
	Person p5 = { "Kuen",30 };

	v_Stack v_stk = StkInit();
	PushStack(v_stk, &p1);
	PushStack(v_stk, &p2);
	PushStack(v_stk, &p3);
	PushStack(v_stk, &p4);
	PushStack(v_stk, &p5);
	printf("count=%d\n\n",GetStkCount(v_stk));

	while (IsStkNull(v_stk)==0) {					//stack is not null
		Person *pTop = GetTopStk(v_stk);			//return the last element
		printf("%s	%d\n",pTop->name,pTop->age);
		PopStack(v_stk);							//pop,count decreases
	}

	printf("ater the pop count=%d\n",GetStkCount(v_stk));
	DestoryStk(v_stk);
}

void main_0518() {
	TestStk();
}