#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>	//offset
#pragma pack (show)	//32bit默认是8，64bit默认是16
typedef struct PeopleInfo{
	int age;		//0~3	
	char *name;		
	double money;	
	char sex;		
	int member;		
}Info;				

typedef struct PeopleInfo2 {
					
	int age;		//0~3
	char name[10];	//4~13	
	char sex;		//14	
	double money;	//16~23	
	int member;		//24~27	
	
}Info2;				//sizeof(Info2)=32

void MemoAlign() {
	printf("siezof(Info)=%d\n",sizeof(Info));
	Info bingo = { 33,"bingo",90,'M',7 };
	int offset1 = offsetof(Info, name);
	int offset2 = offsetof(Info, money);
	int offset3 = offsetof(Info, sex);
	int offset4 = offsetof(Info, member);
	printf("bingo offset:name=%d; money=%d; sex=%d; member=%d\n", offset1, offset2, offset3, offset4);
	printf("sex=%c\n\n", *((char*)(&bingo) +offset3));
}

void MemoAlign2() {
	printf("siezof(Info2)=%d\n", sizeof(Info2));
	Info2 messi = { 33,"Messi",'M',90,7 };
	int offset1 = offsetof(Info2, name);
	int offset2 = offsetof(Info2, sex);
	int offset3 = offsetof(Info2, money);
	int offset4 = offsetof(Info2, member);
	printf("Messi offset:name=%d; sex=%d; money=%d; member=%d\n", offset1, offset2, offset3, offset4);
	printf("name=%s\n", (char *)(&messi) + offset1);
}
void main_0415() {
	MemoAlign();
	MemoAlign2();
}