#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int age;		//0~3
	char name[4];	//4~7
	char sex;		// 8~11
	
}Person;
void main() {
	Person pr = { 32,"CG0",'M'};
	char *p = &pr;
	printf("age=%d;  name=%s; sex=%c\n",pr.age,pr.name, pr.sex);
	printf("&age=%x;&name=%x;s&ex=%x\n",&pr.age,pr.name,&pr.sex);
	printf("*p+4=%s\n", (char *)(p + 4));
	printf("*p+8=%c\n", *(char *)(p + 8));
}