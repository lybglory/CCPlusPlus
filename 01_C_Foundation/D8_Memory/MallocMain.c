#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�Զ���ͷ�ļ���˫��
#include "MallocCase.h"
void main_08_02() {
	printf("Please enter the total number of elements:");
	int num;
	scanf("%d", &num);
	int *pNum = NULL;	
	printf("main-1��&pNum=%x; pNum=%x\n", &pNum, pNum);
	//����Ԫ�ظ�������ѿռ䲢����ÿ��Ԫ�ص�����
	SetMallocElem(&pNum,num);
	
	printf("main-2��&pNum=%x; pNum=%x\n", &pNum, pNum);
	//���ÿ��Ԫ��
	PrintfMallocElem(pNum,num);
	//��Ԫ�ؽ�������
	MallocCompare(pNum,num);
	//������Ԫ��
	PrintfMallocElem(pNum, num);
	if (pNum!=NULL) {
		free(pNum);
		pNum = NULL;
	}
}