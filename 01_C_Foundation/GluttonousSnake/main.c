#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snake.h"	//自定义的头文件
#include <time.h>
void main() {
	
	srand(time(NULL));	//设置随机种子数
	InitWall();
	InitFood();
	InitSnake();
	//Show();
	StartGame();

}