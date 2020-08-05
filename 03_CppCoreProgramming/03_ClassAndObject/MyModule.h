#ifndef MYMODULE_H
#define MYMODULE_H
#include<stdio.h>

	#if __cplusplus
		extern "C" {
	#endif
	
			void func1();
			int func2(int a, int b);

	#if __cplusplus
		}
	#endif
#endif
