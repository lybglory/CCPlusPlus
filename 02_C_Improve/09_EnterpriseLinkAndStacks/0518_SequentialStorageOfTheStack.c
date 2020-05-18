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

