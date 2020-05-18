#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackLknd {					//struct of stack link node
	struct StackLknd *stkLkndNext;
};

struct StackLk {					//struct of stack link
	struct StackLknd stkLkhead;
	int stkCount;
};

typedef	void *VdStklk;				//void * alias

typedef struct {
	char name[10];
	int age;
}Person;

VdStklk StkLkInit() {
	//Restore real and valid data
	struct StackLk *stkLk = (struct StackLk*)malloc(sizeof(struct StackLk));

	if (stkLk==NULL) {
		perror("stack malloc is error");
		return;
	}

	stkLk->stkLkhead.stkLkndNext = NULL;
	stkLk->stkCount = 0;
}

void TestStklk() {}
void main() {
	TestStklk();
}