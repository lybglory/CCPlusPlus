#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
int changedNum = 0;
int ChangeSystem(int sysNum) {
	if (sysNum==0) {
		changedNum=0;
	}
	else {
		int y = sysNum %2;
		sysNum /= 2;
		changedNum=ChangeSystem(sysNum);
		printf("%d", y);
	}
	return changedNum;
}
void main() {
	int num;
	//printf("请输入月份：");
	//scanf("%d", &num);
	//printf("%d个月后有 %d 个兔子", num, Rabbit(num));
	printf("==10进制转二进制==\n请输入需要转换的数:");
	scanf("%d", &num);
	ChangeSystem(num);
}