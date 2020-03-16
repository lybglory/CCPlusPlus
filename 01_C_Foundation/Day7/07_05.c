#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void GetArrInptut(int *p_arr,int n) {
	printf("请输入%d个数组\n",n);
	for (size_t i = 0; i < n; i++){	
		//&*同时出现可以抵消
		//&p_arr[i]==&*(p_arr+i)==p_arr+i
		scanf("%d",&p_arr[i]);
	}
}

void GetArryMax(int *p_arr,int n,int *p_max) {//p_max=&arr_max
	*p_max = p_arr[0];//不能赋0，如果是负数则不好使了
	for (size_t i = 0; i < n; i++){
		if (p_arr[i]> *p_max) {
			*p_max = p_arr[i];
		}
	}
}

main07_05() {
	int arr[5] = { 0 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	//获取输入键盘输入
	GetArrInptut(arr,arrLength);
	//求出数组最大值，需要改变外部变量--引入指针
	int arr_max = 0;
	GetArryMax(arr,arrLength,&arr_max);
	printf("arr_Max=%d",arr_max);
}
