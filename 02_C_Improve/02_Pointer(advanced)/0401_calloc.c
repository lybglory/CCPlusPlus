#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void TestCalloc() {
	int *p = calloc(5,sizeof(int));
	for (size_t i = 0; i < 10; i++)
	{
		printf("p[%d]=%d\n",i,p[i]);
	}
	if (p!=NULL) {
		free(p);
		p = NULL;
	}
}

void TestRealloc() {
	int *p = calloc(5, sizeof(int));
	if (p==NULL) {
		return;
	}

	for (size_t i = 0; i < 5; i++)
	{
		p[i] = i;
		printf("before:p[%d]=%d\n", i, p[i]);
	}
	//
	p = realloc(p,sizeof(int)*10);
	for (size_t i = 0; i < 10; i++)
	{
		printf("after:p[%d]=%d\n", i, p[i]);
	}
	if (p != NULL) {
		free(p);
		p = NULL;
	}
}
void main() {
	//TestCalloc();
	TestRealloc();
}