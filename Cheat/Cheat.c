#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
void main() {
	char sex='F';
	int age=29;
	double money = 20;
	char *pSex = &sex;
	int *pAge = &age;
	double *pMoney = &money;
	printf("pSex=%x; pAge=%x; pMoney=%x\n", pSex, pAge, pMoney);
	printf("*pSex=%c; *pAge=%d; *pMoney=%f\n", *pSex, *pAge, *pMoney);
	while (1)
	{
		printf("�Ա�=%c; ����=%d; ���=%2.0f��\n",sex, age, money);
		Sleep(5000);
	}
}