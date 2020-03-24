﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "snake.h"

//1、初始化墙
extern void InitWall() {
	//控制Y(第几行)
	for (int y = 0; y <=Hight; y++){	

		//控制x轴
		for (int x = 0; x <= Wide; x++) {
			if (x == Wide|| y == Hight) {
				printf(".");
			}
			else 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
//蛇
Snake sk;
//食物
Food fd;
//3、初始化食物
extern void InitFood() {
	fd.x = rand() % Wide;
	fd.y = rand() % Hight;
}


//3、初始化🐍
extern void InitSnake() {
	sk.length = 2;				//初始化长度为2
	sk.point[0].x = Wide / 2;	//🐍头位置
	sk.point[0].y = Hight / 2;

	sk.point[1].x = Wide / 2-1;	//蛇身在蛇头的左边  O🐍
	sk.point[1].y = Hight / 2;	//y轴不变
}

//4、显示
extern void Show() {
	//1、显示食物
	COORD coord;	//光标
	coord.X = fd.x;	//设置食物光标
	coord.Y = fd.y;

	//光标定位
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('*');

	//2、绘制蛇：初始化长度2
	for (size_t i = 0; i < sk.length; i++)
	{
		//设置光标
		coord.X = sk.point[i].x;
		coord.Y = sk.point[i].y;
		//定位
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		//绘制蛇头
		if (i==0) {
			putchar('@');
		}
		else {
			putchar('>');
		}

	}

}

