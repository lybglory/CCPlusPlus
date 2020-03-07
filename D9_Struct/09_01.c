#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person
{
	char name[10];
	int age;
	char Gender;
};

void LearnStruct() {
	struct Person Tangyuan = {"LXM",0,'M'};
	printf("name=%s; age=%d; sex=%c\n",Tangyuan.name,Tangyuan.age,Tangyuan.Gender);
	strcpy(Tangyuan.name,"Chan");
	Tangyuan.age = 1;
	Tangyuan.Gender = 'F';
	printf("name=%s; age=%d; sex=%c\n", Tangyuan.name, Tangyuan.age, Tangyuan.Gender);
}

void main() {
	LearnStruct();
}