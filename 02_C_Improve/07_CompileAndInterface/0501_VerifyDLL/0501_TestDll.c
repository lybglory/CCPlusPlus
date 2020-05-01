#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Factorial.h"
#pragma comment(lib,"./0501_DLL.lib")
void main() {
	int input = 0;
	printf("Enter a number:");
	while (1) {
		scanf("%d", &input);
		if (input > 0) {
			int n = GetFactorial(input);
			printf("%d! = %d\n", input, n);
		}
		else
		{
			break;
		}
	}
}