#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//_declspec	声明外部调用
//dllexport  dll导出
_declspec(dllexport) void Balloon() {
	while (1) {
		malloc(10 * 1024 * 1024);//每次分配10MB内存
		Sleep(1000);
	}
}
