#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackLknd {					//struct of stack link node
	struct StackLknd *next;
};

struct StackLk {					//struct of stack link
	struct StackLknd head;
	int stkCount;
};

typedef	void *VdStklk;				//void * alias

typedef struct {
	char name[10];
	int age;
}Person;

VdStklk StkLkInit() {
	
	struct StackLk *stkLk = (struct StackLk*)malloc(sizeof(struct StackLk));

	if (stkLk==NULL) {
		perror("stack malloc is error");
		return;
	}

	stkLk->head.next = NULL;
	stkLk->stkCount = 0;
}

void PushStklk(VdStklk vdstklk,void *pushData) {	
	if (vdstklk == NULL||pushData==NULL) {
		return;
	}
	struct StackLk *stkLk = vdstklk;			//Restore real and valid data
	struct StackLknd *stkPushData = pushData;	//Fetches the user's first four bytes 
	stkPushData->next = stkLk->head.next;		//head insert
	stkLk->head.next = stkPushData;
	stkLk->stkCount++;
}

void TestStklk() {

}

void main() {
	TestStklk();
}