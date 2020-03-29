#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main() {
	int n1 = 2017;
	int n2 = 2019;
	int n3 = 2020;
	printf("&n1=%d\n&n2=%d\n&n3=%d\n",&n1,&n2,&n3);
}