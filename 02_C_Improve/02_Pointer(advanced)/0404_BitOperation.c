#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void BitTest1() {
	unsigned char a = 2;   //00000010
	unsigned char b = ~a;  //11111101
	printf("ret = %d\n", a); //ret = 2
	printf("ret = %d\n", b); //ret = 253
}
void PrintfArray(int **secPointer,int len) {
	for (size_t i = 0; i < len; i++){
		printf("*secPointer[%d]=%d\n",i, *secPointer[i]);
	}
}

//heap area
void SecondaryPointerInput() {
	int **sec_p = malloc(sizeof(int) * 5);
	memset(sec_p,0, sizeof(int) * 5);
	int array[5] = { 2020,4,4,23,50 };
	int len = sizeof(array) / sizeof(array[0]);
	for (size_t i = 0; i < len; i++){
		sec_p[i] = &array[i];
		printf("sec_p[%d]=%d; &array[%d]=%d\n",i,sec_p[i],i,&array[i]);
	}
	PrintfArray(sec_p,len);
	if (sec_p!=NULL) {
		free(sec_p);
		sec_p = NULL;
	}
}
void main() {
	//BitTest1();
	SecondaryPointerInput();
}