#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Snake sk;
Food fd;
//3、初始化食物
void InitFood() {
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

