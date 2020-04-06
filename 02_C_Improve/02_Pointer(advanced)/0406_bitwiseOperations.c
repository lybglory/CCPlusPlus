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

void main() {
	Parity();
}