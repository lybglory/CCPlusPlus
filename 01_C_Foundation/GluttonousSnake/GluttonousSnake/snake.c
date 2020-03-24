#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snake.h"

extern void InitWall() {
	for (int x = 0; x <= Wide; x++){
		if (x==Wide) {
			printf("|");
		}
		else{
			printf(" ");
		}
	}
}