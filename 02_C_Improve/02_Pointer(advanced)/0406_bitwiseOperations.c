#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Parity() {
	int n;
	while (1) {
		printf("input a number:");
		scanf("%d", &n);
		if ((n & 1) == 0) {
			printf("%d is even number\n", n);
		}
		else
		{
			printf("%d odd number\n", n);
		}
	}
}

void BitwiseOr() {
	int n1 = 4;	//0100
	int n2 = 7;	//0111
				//0111=7
	printf("%d | %d = %d\n",n1,n2,n1|n2);
}

void XOR() {
	int  n1 = 2020;
	int n2 = 407;	//
	printf("before:n1=%d n2=%d\n", n1, n2);
	//1¡¢XOR exchange
	n1 = n1 ^ n2;
	n2 = n1 ^ n2;
	n1 = n1 ^ n2;

	//2¡¢
	//n1 = n1 + n2;
	//n2 = n1 - n2;
	//n1 = n1 - n2;
	//3¡¢
	//int temp = n1;
	//n1 = n2;
	//n2 = temp;

	printf("after :n1=%d n2=%d\n",n1,n2);
}
void main() {
	//Parity();
	//BitwiseOr();
	XOR();
}