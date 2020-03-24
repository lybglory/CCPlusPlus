#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>	//kbhit函数的头文件 
#include "snake.h"
Snake sk;			//蛇
Food fd;			//食物
int dirx = 0;		//方向
int diry = 0;
int tailx = 0;		//尾部
int taily = 0;

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

	sk.point[1].x = (Wide / 2)-1;	//蛇身在蛇头的左边  O🐍
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
			//绘制蛇身
			putchar('>');
		}
	}
	//处理尾巴
	coord.X = tailx;
	coord.Y = taily;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
}

extern void StartGame() {
	char keycode = 'D';
	//蛇的移动的规则条件:不可以碰到到墙
	while (sk.point[0].x>=0 && sk.point[0].x<Wide
		&& sk.point[0].y >= 0 && sk.point[0].y < Hight)
	{	//不可以碰到自己,必须是蛇身
		for (size_t i = 1; i < sk.length; i++)
		{
			if (sk.point[0].x==sk.point[i].x &&sk.point[0].y== sk.point[i].y) {
				return;
			}
		}

		//碰到食物
		if (sk.point[0].x==fd.x&&sk.point[0].y==fd.y) {
			sk.length++;	//蛇变长
			InitFood();		//初始化食物
		}

		//控制蛇移动
		//is press?
		if (_kbhit()) {
			keycode = _getch();
		}

		//判断是哪个键
		switch (keycode)
		{
		case 'w':
		case 'W':
			dirx = 0;	//up
			diry = -1;
			break;
		case 's':
		case 'S':
			dirx = 0;	//Down
			diry = 1;
			break;
		case 'a':
		case 'A':
			dirx = -1;	//Left
			diry = 0;
			break;
		case 'd':
		case 'D':
			dirx = 1;	//Right
			diry = 0;
			break;
		}
		//move 
		//记录蛇尾巴
		tailx = sk.point[sk.length - 1].x;
		taily = sk.point[sk.length - 1].y;

		//除了蛇头，蛇身从后往前挪(倒叙循环)
		for (int j=sk.length-1; j >0; j--)
		{
			sk.point[j].x = sk.point[j-1].x;
			sk.point[j].y = sk.point[j - 1].y;
		}
		//update蛇头位置
		sk.point[0].x += dirx;
		sk.point[0].y += diry;
		//update显示
		Show();
		Sleep(500);

	}//while_end
}

