#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//_declspec	�����ⲿ����
//dllexport  dll����
_declspec(dllexport) void Balloon() {
	while (1) {
		malloc(10 * 1024 * 1024);//ÿ�η���10MB�ڴ�
		Sleep(1000);
	}
}
