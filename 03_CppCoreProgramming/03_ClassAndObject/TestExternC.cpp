#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0

#ifdef __cplusplus
extern "C" {
#if 0
	void func1();
	int func2(int a, int b);
#else
#include"MyModule.h"
#endif
}

#endif

#else

extern "C" void func1();
extern "C" int func2(int a, int b);

#endif

void main_ExternC() {
	func1();
	cout << func2(10, 20) << endl;
}
