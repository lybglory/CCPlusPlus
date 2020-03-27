#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *MemoConsider(int *p) {
	int temp = 2020;
	p = (int *)malloc(sizeof(int));
	memset(p,0,sizeof(int));
	return p = &temp;
	printf("*p=%d\n", *p);
}

void MemoConsider2(int **p) {
	int temp = 2020;
	*p = (int*)malloc(sizeof(int));
	memset(*p, 0, sizeof(int));
	*p = &temp;
	printf("**p=%d\n", **p);
}

void main() {
	int *p_n = NULL;
	MemoConsider2(&p_n);
	printf("*p_n=%d\n",*p_n);

}