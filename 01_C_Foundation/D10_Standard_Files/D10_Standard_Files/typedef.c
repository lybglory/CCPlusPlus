#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int intType;

typedef struct {
	char *name;
	int age;
	char sex;
}PR;
typedef struct Person{
	char* name;
	int age;
	char sex;
}Prs;
void tydefStru() {
	//struct Person Messi = { "Messi",30,'M' };
	//PR Messi= { "Messi",30,'M' };
	Prs Messi = { "Messi",30,'M' };
	printf("%s %d %c\n",Messi.name,Messi.age,Messi.sex);
}
void TestTypedef() {
	int n1 = 2020;
	intType nt = 316;
	printf("n1=%d; nt=%d\n",n1,nt);
}
void main() {
	//TestTypedef();
	tydefStru();
}