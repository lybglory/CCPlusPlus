#pragma once
#define Wide 50		//长：50
#define Hight 20	//高：20
extern void InitWall();

//2、定义🐍、食物类型

//🐍的坐标
typedef struct{
	int x;
	int y;
}SnakePoint;

//🐍的类型：长度、坐标
typedef struct  {
	int length;
	SnakePoint point[Wide*Hight];
}Snake;

//食物
typedef struct {
	int x;
	int y;

}Food;

extern void InitSnake();