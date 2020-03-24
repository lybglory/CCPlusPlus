#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snake.h"	//自定义的头文件
#include <time.h>
#include <Windows.h>
void main() {
	
	srand(time(NULL));	//设置随机种子数
	//cursor visible
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = FALSE;
	curInfo.dwSize = sizeof(curInfo);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	InitWall();
	InitFood();
	InitSnake();
	StartGame();

}