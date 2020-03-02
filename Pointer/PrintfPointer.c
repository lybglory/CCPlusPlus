#include <stdio.h>
#include<stdlib.h>
#include<Windows.h>
void main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	//数组名表示数组首元素地址
	int *p_arr = arr;
	printf("arr=%x; p_arr=%x; &p_arr=%x; *p_arr=%d\n",arr,p_arr,&p_arr,*p_arr);
	for (size_t i = 0; i < arrLength; i++)
	{
		printf("&arr[%d]=%x,arr[i]=%d\n",i,arr+i,arr[i]);
	}
	while (1) {
		printf("*p_arr=%d\n",*p_arr);
		Sleep(1000);
	}
}