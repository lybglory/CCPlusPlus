#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person {
	char* name;
	int age;
};

//Format:return value(variable name)(formal parameter type)
void CallbackArr(void(* pFunc)(void *),void(* data),int length,int eleSize) {
	char *pArr = data;
	for (int i = 0; i < length; i++)
	{
		char *tempAddr = pArr +eleSize * i;
		pFunc(tempAddr);
	}
}
void PrintfIntArr(void(* data)) {
	int *num = data;
	printf("IntArr: %d\n",*num);
}
void PrintfStrucArr(void *data) {
	struct Person *pr = (struct Person *)data;
	printf("person: name=%s; age=%d\n",pr->name,pr->age);
}

void CallbkFindElement(int(*pFubc)(void *,void *),void(* dataArr),void(* lookupData),int length,int eleSize) {
	char* pArr = dataArr;
	for (int i = 0; i < length; i++)
	{
		char *tempAddr = pArr + eleSize * i;
		if (pFubc(tempAddr,lookupData) == 1) {
			printf(" has been found!\n");
		}
	}

}

int FindElement(void *pr1,void *pr2) {
	struct Person *p1 = (struct Person *)pr1;
	struct Person *p2 = (struct Person *)pr2;
	if (strcmp(p1->name,p2->name)==0 && p1->age == p2->age) {
		printf("the element: name=%s; age=%d ",p1->name,p1->age);
		return 1;
	}
	else {
		return -1;
	}
}

void main_0428() {
	int yearArr[5] = {2020,2019,2018,2017,2016};
	int yearLeng = sizeof(yearArr) / sizeof(yearArr[0]);
	int eleSize = sizeof(yearArr[0]);
	CallbackArr(PrintfIntArr,yearArr, yearLeng, eleSize);
	struct Person pr[] = { {"Messi",33},{"bin",30},{"Mei",30} };
	CallbackArr(PrintfStrucArr, pr, sizeof(pr) / sizeof(pr[0]), sizeof(pr[0]));
	struct Person prLookup = {"Mei",30};
	CallbkFindElement(FindElement, pr,&prLookup, sizeof(pr) / sizeof(pr[0]), sizeof(pr[0]));
}