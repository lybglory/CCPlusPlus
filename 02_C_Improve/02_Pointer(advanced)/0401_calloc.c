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
void main() {
	TestCalloc();
}