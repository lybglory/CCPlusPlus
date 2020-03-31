#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void StrReverse1(char *p) {
	int len = strlen(p);
	for (int i = 0; i < len/2; i++){
		//两两交换
		char temp= p[i];
		p[i] = p[len - 1 - i];
		p[len - 1 - i] = temp;
	}
}

void StrReverse2(char *p) {
	int len = strlen(p);
	char *p_start = p;		//首地址
	char *p_end =p_start+len-1;

	while (p_start < p_end) {
		char temp = *p_start;
		*p_start = *p_end;
		*p_end = temp;
		p_start++;
		p_end--;
	}
}

void main() {
	char str[30] = "Date:2020/04/01 1:20";
	printf("before=%s\n",str);
	//StrReverse1(str);
	StrReverse2(str);
	printf("after =%s\n",str);
}