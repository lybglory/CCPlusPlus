#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Linkls {
	struct Linknd *lklsHead;
	int lkndCount;
};
//node just record pointer arear
struct Linknd {
	struct Linknd *lkndNext;
};

typedef struct {
	int *pAddr;	//Any four-byte data type is ok
	char *name;
	int age;

}PersonInfo;
//void * alias
typedef void *v_etpLink;

v_etpLink InitEnterpriseLinkls() {
	struct Linkls *lkls = malloc(sizeof(struct Linkls));
	if (NULL==lkls) {
		perror("malloc error");
		return;
	}
	lkls->lkndCount = 0;
	lkls->lklsHead->lkndNext = NULL;	//valid data
	return lkls;
}


void main() {

}