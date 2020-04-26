#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Greeting(char *date,char *dailogue) {
	printf("%s:%s\n",date,dailogue);
}

void FuncPointerDefined1() {
	//
	typedef void(*pFunc)(char *date, char *dailogue);
	char *p1 = "defined1:2020/04/26";
	char *p2 = "You are booked on flight numberCX167";
	//
	pFunc pfunc1 = Greeting;
	pfunc1(p1, p2);
}

void FuncPointerDefined2() {
	typedef void(pFunc)(char* date, char* dailogue);
	char* p1 = "deinfed2:2020/04/26";
	char* p2 = "I would like to reserve a round-trip ticket to Parise,please";
	pFunc *pfunc1 = Greeting;
	pfunc1(p1, p2);
}
void main() {
	//FuncPointerDefined1();
	FuncPointerDefined2();
}

