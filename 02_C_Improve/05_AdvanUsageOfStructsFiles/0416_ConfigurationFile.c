#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
void main() {
	int lines=GetFileLine("config.txt");
	printf("lines=%d\n",lines);
}