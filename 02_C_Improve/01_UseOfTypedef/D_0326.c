#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int age;		//0~3
	char name[4];	//4~7
	char sex;		// 8~11
	int money;		//12~15
	
}Person;
void main_0326() {
	Person pr = { 30,"LZZ",'M',90};
	char *p = &pr;
	printf("age=%d;  name=%s; sex=%c; money=%d\n",pr.age,pr.name, pr.sex,pr.money);
	printf("&age=%x; &name=%x; &sex=%x;&money=%x\n",&pr.age,pr.name,&pr.sex,&pr.money);
	printf("(p+4)=%s\n", (char *)(p + 4));
	printf("(p+8)=%c\n", *(char *)(p + 8));
	printf("(p+12)=%d\n", *(int *)(p + 12));
}