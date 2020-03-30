#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test01() {
	char *p = NULL;
	printf("p=%d\np+1=%d\n",p,p+1);

	double *dp = NULL;
	printf("dp=%d\ndp+1=%d\n", dp, dp + 1);

}
void main() {
	test01();
}