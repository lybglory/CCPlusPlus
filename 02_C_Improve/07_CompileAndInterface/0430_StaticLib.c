#include "PrintfAnyArr.h"
void CommPrintfArr(void(*callbk)(void), void* pArr, int len, int eleSize) {
	for (int i = 0; i < len; i++)
	{
		char* p = (char*)pArr + i * eleSize;
		callbk(p);
	}
}