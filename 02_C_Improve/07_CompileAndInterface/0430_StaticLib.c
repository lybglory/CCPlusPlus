#include "PrintfAnyArr.h"
extern void CallbkPrintfIntArr(void* data) {
	int* num = (int*)data;
	printf("%d\n", *num);
}

extern void CommPrintfArr(void(*callbk)(void), void* pArr, int len, int eleSize) {
	for (int i = 0; i < len; i++)
	{
		char* p = (char*)pArr + i * eleSize;
		callbk(p);
	}
}