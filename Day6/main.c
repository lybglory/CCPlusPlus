#include <stdio.h>
#include <stdlib.h>
#include "Func.h"

void main() {
	int numbers[5] = {0};
	int length = sizeof(numbers) / sizeof(numbers[0]);
	int max = GetMax(numbers);
	printf("max=%d\n", max);
	for (size_t i = 0; i < length; i++)
	{
		printf("%d ", numbers[i]);
	}
}