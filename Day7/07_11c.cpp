#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main() {
	char dest[50] = "Tan Yuan";
	char src[] = "-Welcome to the world";
	//strcpy(dest, src);
	//strncpy(dest,src,10);
	//strcat(dest,src);
	strncat(dest,src,8);
	printf("%s\n", dest);
}
