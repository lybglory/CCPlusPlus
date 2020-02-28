#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main() {
	//char dest[50] = "Tan Yuan";
	//char src[] = "-Welcome to the world";
	//strcpy(dest, src);
	//strncpy(dest,src,10);
	//strcat(dest,src);
	//strncat(dest,src,8);
	//printf("%s\n", dest);
	char str1[32] = "TanYuan";
	printf("str1=%s\nÇëÊäÈëÒ»¸ö×Ö·û´®:\n",str1);
	char chrInput[32] = "";
	fgets(chrInput, sizeof(chrInput), stdin);
	if (strcmp(str1, chrInput) == 0) {
		printf("%s==%s\n",str1,chrInput);
	}
	else if (strcmp(str1, chrInput) > 0) {
		printf("%s>%s\n", str1, chrInput);
	}
	else {
		printf("%s<%s\n", str1, chrInput);
	}
}
