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

void FuncPointerDefined3() {
	void(*pFunc)(char *date, char* dailogue)=Greeting;
	char *p1 = "deinfed3:2020/04/26";
	char *p2 = "Please call back on Friday to reconfirm";
	pFunc(p1,p2);
}
void FuncPointArr() {
	void (*pFuncArr[3])(char *date, char *dailogue);
	pFuncArr[0]= FuncPointerDefined1;
	pFuncArr[1] = FuncPointerDefined2;
	pFuncArr[2] = FuncPointerDefined3;
	//called
	for (size_t i = 0; i < sizeof(pFuncArr)/sizeof(pFuncArr[0]); i++)
	{
		pFuncArr[i]("","");
	}

}
struct Person { 
	char *name;
	int age;
};
void PrintfInt(void *n) {
	int *num =(int *)n;
	printf("int=%d\n",*num);
}

void PrintfFloat(void *n) {
	float *flnum = (float *)n;
	printf("float=%0.1f\n", *flnum);
}

void PrintfStruct(void *data) {
	struct Person *struPerson = (struct Person *)data;
	printf("name=%s; age=%d\n",struPerson->name,struPerson->age);
}
void CallBackFunction(void(*pFunc)(void *),void(*n) ) {
	pFunc(n);
}

void main_0426() {
	//FuncPointerDefined1();
	//FuncPointerDefined2();
	//FuncPointerDefined3();
	//FuncPointArr();
	//int n = 2020;
	//CallBackFunction(PrintfInt,&n);
	//float score = 99.7f;
	//CallBackFunction(PrintfFloat, &score);
	//struct Person pr = {"Messi",33};
	//CallBackFunction(PrintfStruct, &pr);


}

