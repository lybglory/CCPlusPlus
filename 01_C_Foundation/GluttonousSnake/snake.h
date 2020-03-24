#pragma once
#define Wide 40		//长：50
#define Hight 10	//高：20
extern void InitWall();

//2、定义🐍、食物类型

//🐍的坐标
typedef struct{
	int x;
	int y;
}SnakePoint;

//🐍的类型：长度、坐标
typedef struct  {
	//蛇的长度
	int length;
	//蛇的坐标
	SnakePoint point[Wide*Hight];
}Snake;

//食物
typedef struct {
	int x;
	int y;

}Food;
extern void InitFood();
extern void InitSnake();
extern void Show();
extern void StartGame();