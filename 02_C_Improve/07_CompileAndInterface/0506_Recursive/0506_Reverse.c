#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Fibonacci(int num) {
	if (num == 1 || num == 2) {
		return 1;
	}
	//1 1 2 3 5 8 11 19 
	return Fibonacci(num - 1) + Fibonacci(num - 2);

}
void Func0() {
	int n = 0;

	while (1) {
		scanf("%d", &n);
		if (n > 0) {
			printf("fibonacc(%d)=%d\n", n, Fibonacci(n));
		}
	}

}

void ReverseStr1(char *p) {
	if (p == NULL || *p == '\0') {
		return;
	}
	ReverseStr1(p+ 1);
	printf("%c",*p);
}
char dest[1024];
void ReverseStr2(char* p) {
	if (p == NULL) {
		return;
	}
	int len = strlen(p);
	if (*p == '\0') {
		dest[len] = '\0';
		return;
	}
	//printf("strlen(p)=%d\n",len);//14
	ReverseStr2(p +1);
	strncat(dest,p,1);
}

void Func1(char *str) {
	ReverseStr1(str);
}

void Func2(char *str) {
	ReverseStr2(str, dest);
	printf("%s\n",dest);

}
void main() {
	char str[] = "Hello May 6th!";
	printf("%s\n",str);
	Func1(str);
	printf("\n");
	Func2(str);
}