#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CopyStr1(char* p_src, char* p_dest) {
	int len = strlen(p_src);
	int i = 0;
	while (i < len) {
		p_dest[i] = p_src[i];
		i++;
	}
	p_dest[len] = '\0';
}

void CopyStr2(char* p_src, char* p_dest) {
	while (*p_src != '\0') {
		*p_dest = *p_src;
		p_src++;
		p_dest++;
	}
	//
	*p_dest = '\0';
}


void CopyStr3(char* p_src, char* p_dest) {
	while (*(p_dest++)=*(p_src++)) {
		
	}
}
void main() {
	char src[] = "2020/03/31.Today is cloudy";
	char str[100];
	//CopyStr1(src,str);
	//CopyStr2(src, str);
	CopyStr3(src, str);
	printf("str=%s\n",src);
}