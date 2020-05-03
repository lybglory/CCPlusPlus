#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Fibonacci(int num) {
	if (num==1||num==2) {
		return 1;
	}
	//1 1 2 3 5 8 11 19 
	return Fibonacci(num - 1)+Fibonacci(num-2);

}
void main() {
	int n=0;

	while (1){	
		scanf("%d", &n);
		if (n>0) {
			printf("fibonacc(%d)=%d\n", n, Fibonacci(n));
		}
	}
	
}