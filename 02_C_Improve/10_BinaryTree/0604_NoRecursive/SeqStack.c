#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqStack.h"
v_Stack SkInit() {
	OrderStack *stk = (OrderStack *)malloc(sizeof(OrderStack));
	if (stk==NULL) {
		return NULL;
	}

	memset(stk->dataArr,0,sizeof(v_Stack)*stackMax);
	stk->stackCount = 0;
	return stk;
}

//Push
void PushStack(v_Stack v_stk, void *pushData) {
	if (v_stk ==NULL||pushData==NULL) {
		return;
	}
	OrderStack *stk = v_stk;
	if (stk->stackCount==stackMax) {
		return;			//stack is full
	}

	stk->dataArr[stk->stackCount] = pushData;
	stk->stackCount++;
}

void PopStack(v_Stack v_stk) {
	if (v_stk == NULL) {
		return;
	}
	OrderStack *stk = v_stk;		//还原真是有效的结构体类型
	stk->dataArr[stk->stackCount-1] = NULL;
	stk->stackCount--;
}

v_Stack GetTopStk(v_Stack v_stk) {
	if (v_stk == NULL) {
		return;
	}
	OrderStack* stk = v_stk;		//Restores truly efficient structural types
	if (stk->stackCount==0) {
		return;
	}
	return stk->dataArr[stk->stackCount-1];
}

int GetStkCount(v_Stack v_stk) {

	if (v_stk == NULL) {
		return;
	}
	OrderStack *stk = v_stk;		//Restores
	return stk->stackCount;
}

int IsStkNull(v_Stack v_stk) {
	if (v_stk == NULL) {
		return -1;
	}
	OrderStack* stk = v_stk;		//Restores
	if (stk->stackCount==0) {
		return 1;	//is null
	}
	return 0;		//not null;
}

void DestroyStk(v_Stack v_stk) {
	if (v_stk == NULL) {
		return;
	}
	free(v_stk);
	v_stk = NULL;
}
