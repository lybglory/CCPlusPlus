#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Minus(a,b) a-b

void MacroFun() {
	int n1 = 2020;
	int n2 = 2019;
	int result = Minus(n1, n2);

	printf("result=%d\n",result);
}
void main() {
	MacroFun();
}