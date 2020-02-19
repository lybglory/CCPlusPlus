#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ChangeNum(int *PointA) {
	*PointA = 2020;
}

//数组作为参数传递，传递的是元素的首地址。地址4个字节
//void printArrary(int a[10], int n)
//void printArrary(int a[], int n)
void printArrary2(int* a, int n)
{
	printf("printArrary数组大小=%d\n", sizeof(a));//输出结果:4
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

main_07() {
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = sizeof(a) / sizeof(a[0]);
	//数组名做函数参数：请将数组长度传递过去
	printArrary2(a, n);

}
main_1() {
	int num = 2019;
	printf("改变前：num=%d\n", num);
	ChangeNum(&num);
	printf("改变后：num=%d",num);
}