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

typedef	void *VdStkLk;				//void * alias

typedef struct {
	void *pAddr;					//four byte
	char name[10];
	int age;
}Person;

VdStkLk StkLkInit() {
	
	struct StackLk *stkLk = (struct StackLk*)malloc(sizeof(struct StackLk));

	if (stkLk==NULL) {
		perror("stack malloc is error");
		return;
	}

	stkLk->head.next = NULL;
	stkLk->stkCount = 0;
}

void PushStklk(VdStkLk vdStkLk,void *pushData) {	
	if (vdStkLk == NULL||pushData==NULL) {
		return;
	}
	struct StackLk *stkLk = vdStkLk;			//Restore real and valid data
	struct StackLknd *stkPushData = pushData;	//Fetches the user's first four bytes 
	stkPushData->next = stkLk->head.next;		//head insert
	stkLk->head.next = stkPushData;
	stkLk->stkCount++;
}

void PopStklk(VdStkLk vdStklk) {
	if (vdStklk == NULL) {
		return;
	}
	struct StackLk *stkLk = vdStklk;			//Restore real and valid data
	if (stkLk->stkCount==0) {
		return;
	}
	struct StackLknd *stkLkndCurr = stkLk->head.next;	//pointer valid data
	//free(stkLkndCurr);								//user data no need to free
	stkLk->head.next = stkLkndCurr->next;											
	stkLk->stkCount--;
}

VdStkLk GetTopStkLk(VdStkLk vdStklk) {
	if (vdStklk == NULL) {
		return;
	}
	struct StackLk *stkLk = vdStklk;			//Restore real and valid data
	if (stkLk->stkCount == 0) {
		return NULL;
	}

	return stkLk->head.next;					//return valid data
}

int GetStkLkCount(VdStkLk vdStkLk) {
	if (vdStkLk == NULL) {
		return -1;
	}
	struct StackLk *stkLk = vdStkLk;			//Restore real and valid data

	return stkLk->stkCount;

}

int StkLkIsNULL(VdStkLk vdStklk) {
	if (vdStklk == NULL) {
		return -1;
	}
	struct StackLk *stkLk = vdStklk;			//Restore real and valid data
	if (stkLk->stkCount==0) {
		return 1;				//stack link is null,return 1.
	}
	return 0;					//stack link is not null.return 0.
}

void TestStklk() {
	Person p1 = { NULL,"Messi",33 };
	Person p2 = { NULL,"Bin",18 };
	Person p3 = { NULL,"Mei",18 };
	Person p4 = { NULL,"Soup",1 };
	Person p5 = { NULL,"Kuen",29 };

	VdStkLk vdStkLk = StkLkInit();
	PushStklk(vdStkLk, &p1);
	PushStklk(vdStkLk, &p2);
	PushStklk(vdStkLk, &p3);
	PushStklk(vdStkLk, &p4);
	PushStklk(vdStkLk, &p5);
	printf("count of linked stack=%d\n\n",GetStkLkCount(vdStkLk));

	while (StkLkIsNULL(vdStkLk)==0)
	{
		struct StackLk *stkLk = vdStkLk;			//Restore real and valid data
		Person *pr = stkLk->head.next;
		printf("%s	%d\n",pr->name,pr->age);

		PopStklk(vdStkLk);
	}
	printf("ater count of pop stack=%d\n\n", GetStkLkCount(vdStkLk));
}

void main() {
	TestStklk();
}