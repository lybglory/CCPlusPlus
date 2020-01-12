#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
Rabbit(int x)
{
	int result;
	if (x == 1 || x == 2) {
		result = 1;
	}else {
		result = Rabbit(x - 1) + Rabbit(x - 2);
	}
	return result;
}

void main() {
	int num;
	printf("请输入月份：");
	scanf("%d", &num);
	printf("%d个月后有 %d 个兔子", num, Rabbit(num));
}