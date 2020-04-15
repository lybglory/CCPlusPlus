#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>	//offset
#pragma pack (show)	//32bit默认是8，64bit默认是16
typedef struct PeopleInfo{
	int age;				//0~3
	char *name;		//4~7	//8~15		
	double money;	//8~15	//16~22
	char sex;		//16~17	//24~27
	int member;				//28~31
}Info;

void MemoAlign() {
	printf("siezof(Info)=%d\n",sizeof(Info));
	Info messi = { 33,"Messi",90,'M' };
	int offset=offsetof(Info, member);
	printf("offset=%d\n",offset);
}
void main() {
	MemoAlign();
}