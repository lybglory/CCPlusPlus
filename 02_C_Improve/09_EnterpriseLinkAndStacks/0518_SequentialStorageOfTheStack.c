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

v_Stack TopStack(v_Stack v_stk) {
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
