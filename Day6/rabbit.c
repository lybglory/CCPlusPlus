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
	//printf("�������·ݣ�");
	//scanf("%d", &num);
	//printf("%d���º��� %d ������", num, Rabbit(num));
	printf("==10����ת������==\n��������Ҫת������:");
	scanf("%d", &num);
	ChangeSystem(num);
}