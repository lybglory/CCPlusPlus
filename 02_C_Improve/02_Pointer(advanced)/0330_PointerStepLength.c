#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
void test01() {
	char *p = NULL;
	printf("p=%d\np+1=%d\n",p,p+1);

	double *dp = NULL;
	printf("dp=%d\ndp+1=%d\n", dp, dp + 1);

}
struct Person {
	int age;		//0~3
	char name[10];	//4~13
	char sex;		//14~15
	int money;		//16~19

};
void GetStructValue() {
	struct Person pr = { 30,"Messi",'M',900 };
	char *p = &pr;
	printf("offset money=%d\n",offsetof(struct Person,money));
	printf("money=%d\n", *(int *)(char *)(p + 16));
	printf("sex=%c\n", *(char *)(p + offsetof(struct Person, sex)));
	printf("name=%s\n", (char*)(p + offsetof(struct Person, name)));
}

void GetStructValue2() {
	struct Person pr = { 30,"Messi",'M',900 };
	printf("offset money=%d\n", offsetof(struct Person, money));
	printf("money=%d\n", *(int*)((char*)(&pr) + 16));
	printf("sex=%c\n", *((char*)(&pr) + offsetof(struct Person, sex)));
	printf("name=%s\n", (char*)(&pr) + offsetof(struct Person, name));
}
void main_0330() {
	//test01();
	//GetStructValue();
	//GetStructValue2();
}