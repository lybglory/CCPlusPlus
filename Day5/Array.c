#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
	int num[5] = { 0 };
	int numLength = sizeof(num) / sizeof(num[0]);
	int maxNum = 0;
	int minNum = 0;
	printf("������%d��Ԫ��\n", numLength);
	for (int m=0;m< numLength;m++)
	{
		scanf("%d", &num[m]);
	}

	//for (int i=0;i< numLength;i++)
	//{

	//	int tempNum = 0;
	//	if (num[i]> maxNum) {
	//		maxNum =num[i];
	//	}
	//	else if (num[i] <minNum) {
	//		minNum = num[i];
	//	}

	//}
	//printf("Max=%d; Min=%d\n", maxNum,minNum);

	////��������
	//for (int k=0;k<numLength/2;k++)
	//{
	//	int tempNum = num[k];
	//	num[k] = num[numLength -1- k];
	//	num[numLength-1 - k] = tempNum;
	//}
	////exchange���
	//printf("����������");
	//for (int k = 0; k < numLength; k++)
	//{
	//	
	//	printf("%d ", num[k]);
	//}

	for (int x = 0; x < numLength-1; x++)
	{
		for (int y=0;y< numLength-1-x;y++)
		{	//ð�ݽ���ǰ��Ƚϣ����������������Ѵ������ǰŲ
			if (num[y]<num[y+1]) {
				int tempy = num[y];
				num[y] = num[y + 1];
				num[y + 1] = tempy;
			}
		}
	}
	//ð���������
	printf("ð�ݽ��������");
	for (int k = 0; k < numLength; k++)
	{

		printf("%d ", num[k]);
	}

}