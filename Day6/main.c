#include <stdio.h>
#include <stdlib.h>
#include "Func.h"

void main() {
	int numbers[5] = {'a'+rand()%26,'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26,'a' + rand() % 26 },*p;
	p = numbers;
	int length = sizeof(numbers) / sizeof(int);//³¤¶È
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", numbers[i]);
	}
	int max = GetMax(numbers,length);
	printf("\n max=%d", max);
	
}