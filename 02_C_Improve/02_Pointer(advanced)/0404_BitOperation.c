#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void BitTest1() {
	unsigned char a = 2;   //00000010
	unsigned char b = ~a;  //11111101
	printf("ret = %d\n", a); //ret = 2
	printf("ret = %d\n", b); //ret = 253
}
void main() {
	BitTest1();
}