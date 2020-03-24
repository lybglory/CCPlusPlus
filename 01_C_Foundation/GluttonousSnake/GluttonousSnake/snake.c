#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snake.h"

extern void InitWall() {
	//控制Y(第几行)
	for (int y = 0; y <=Hight; y++){	

		//控制x轴
		for (int x = 0; x <= Wide; x++) {
			if (x == Wide) {
				printf("|");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	
}