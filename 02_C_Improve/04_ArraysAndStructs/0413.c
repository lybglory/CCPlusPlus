#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char *name;
	int age;

}Person;
Person **StructHeapArea() {
	Person **tempStruct = (Person **)malloc(sizeof(Person *)*3);
	for (size_t i = 0; i < 3; i++)
	{
		tempStruct[i] = (Person *)malloc(sizeof(Person));
		tempStruct[i]->name = (char *)malloc(sizeof(char)*10);
		sprintf(tempStruct[i]->name,"L%dC",i+1);
		tempStruct[i]->age = i+1;
	}
	if (tempStruct!=NULL) {
		return tempStruct;
	}
	else
	{
		return NULL;
	}
}

//
void PrintfStructArr(Person **prs,int length) {
	for (size_t i = 0; i < length; i++)
	{
		printf("name=%s; age=%d\n",prs[i]->name,prs[i]->age);
	}
}

//free heap area
void FreeStructHeap(Person **prs, int length) {
	if(prs==NULL||length<=0) {
		perror("prs is null");
		return;
	}
	for (size_t i = 0; i < length; i++)
	{	//free name
		if (prs[i]->name!=NULL) {
			free(prs[i]->name);
			prs[i]->name = NULL;
		}
		//free struct
		if (prs[i]!=NULL) {
			free(prs[i]);
			prs[i] = NULL;
		}
	}
	//
	if (prs!=NULL) {
		free(prs);
		prs = NULL;
	}
}
void main() {
	Person **people = NULL;
	people = StructHeapArea();
	PrintfStructArr(people,3);
	//free
	FreeStructHeap(people,3);
}