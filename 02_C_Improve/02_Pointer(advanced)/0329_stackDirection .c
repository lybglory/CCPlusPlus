#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TestStackDirect() {
	int n1 = 2017;
	int n2 = 2019;
	int n3 = 2020;
	printf("&n1=%d\n&n2=%d\n&n3=%d\n", &n1, &n2, &n3);
}
void HowMemoStored() {
	int hex = 0x54321;
	char *p = &hex;
	printf("*p=%x\n",*p);			//21
	printf("*(p+1)=%x\n", *(p+1));	//43
	printf("*(p+2)=%x\n", *(p + 2));//5
}
void main() {
	//TestStackDirect();
	HowMemoStored();
}