#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **HeapArea(int lines) {
	if (lines < 0) {
		return NULL;
	}
	char text[] = "山寺桃花始盛开，";
	char **temp = (char**)malloc(sizeof(char*)*lines);
	if (temp ==NULL) {
		return NULL;
	}
	for (size_t i = 0; i < lines; i++)
	{
		temp[i] = (char *)malloc(strlen(text)+1);
		switch (i)
		{
		case 0:
			strcpy(temp[i], "人间四月芳菲尽，");
			break;
		case 1:
			strcpy(temp[i], "山寺桃花始盛开。");
			break;
		case 2:
			strcpy(temp[i], "长恨春归无觅处，");
			break;
		case 3:
			strcpy(temp[i], "不知转入此中来。");
			break;
		}
	}
	return temp;
}

void PrintfSecPoint(char **p,int length) {
	for (size_t i = 0; i < length; i++)
	{
		printf("%s\n",p[i]);
	}
}
void FreeHeapArea(char **p,int len) {
	if (p==NULL) {
		return;
	}
	for (size_t i = 0; i < len; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
}

void IterateThrough(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void StorageCharacter() {
	int arr[][3] = {
		{ 2020, 2019, 2018 },
		{ 2017, 2016, 2015 },
		{ 2014, 2013, 2012 }
	};

	int arr2[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr2) / sizeof(int);

	int* p = (int*)arr;
	IterateThrough((int*)arr, len);
	IterateThrough((int*)arr2, len);
}


//二维数组的第1种形式
void PrintArray01(int arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("arr1[%d][%d]:%d ", i, j, arr[i][j]);
		}
		printf("\n");
	}
}

//二维数组的第2种形式
void PrintArray02(int arr[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("arr2[%d][%d]:%d ", i, j, arr[i][j]);
		}
		printf("\n");
	}
}

//二维数组的第3种形式
void PrintArray03(int(*arr)[3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("arr3[%d][%d]:%d ", i, j, arr[i][j]);
		}
		printf("\n");
	}
}

void FormalParameter() {

	int arr[][3] = {
		{ 2020, 2019, 2018 },
		{ 2017, 2016, 2015 },
		{ 2014, 2013, 2012 }
	};

	PrintArray01(arr);
	PrintArray02(arr);
	PrintArray03(arr);
}
typedef struct  {
	char* name;
	int age;
}Person;
void StrucAssignOper() {
	Person bin;
	bin.name = (char*)malloc(strlen("bin")+1);
	memset(bin.name, 0, strlen("bin") + 1);
	strcpy(bin.name,"bin");
	bin.age = 20;
	Person messi;
	messi.age = 30;
	messi.name = (char *)malloc(strlen("Messi")+1);
	memset(messi.name,0, strlen("Messi") + 1);
	strcpy(messi.name, "Messi");
	//bin = messi;		//浅拷贝之后，一旦free，会有内存泄漏
	
	
	//--解决办法：先释放被赋值属性的堆区空间
	if (bin.name!=NULL) {
		free(bin.name);
		bin.name = NULL;
	}
	//然后再重新分配
	bin.name = (char*)malloc(strlen(messi.name)+1);
	strcpy(bin.name,messi.name);
	//----
	printf("bin  :%s %d\n", bin.name, bin.age);
	printf("messi:%s %d\n", messi.name, messi.age);

	if (messi.name!=NULL) {
		free(messi.name);
		messi.name = NULL;
	}
	if (bin.name != NULL) {
		free(bin.name);
		bin.name = NULL;
	}
}
void main() {
	//int lines = 4;
	//char **p=HeapArea(lines);
	//PrintfSecPoint(p,lines);
	//FreeHeapArea(p, lines);
	//StorageCharacter();
	//FormalParameter();
	StrucAssignOper();
}