#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void GetArrInptut(int *p_arr,int n) {
	printf("������%d������\n",n);
	for (size_t i = 0; i < n; i++){	
		//&*ͬʱ���ֿ��Ե���
		//&p_arr[i]==&*(p_arr+i)==p_arr+i
		scanf("%d",&p_arr[i]);
	}
}

void GetArryMax(int *p_arr,int n,int *p_max) {//p_max=&arr_max
	*p_max = p_arr[0];//���ܸ�0������Ǹ����򲻺�ʹ��
	for (size_t i = 0; i < n; i++){
		if (p_arr[i]> *p_max) {
			*p_max = p_arr[i];
		}
	}
}

main07_05() {
	int arr[5] = { 0 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	//��ȡ�����������
	GetArrInptut(arr,arrLength);
	//����������ֵ����Ҫ�ı��ⲿ����--����ָ��
	int arr_max = 0;
	GetArryMax(arr,arrLength,&arr_max);
	printf("arr_Max=%d",arr_max);
}
