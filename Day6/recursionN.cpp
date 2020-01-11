#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int z = 1;
double dTemp = 0;
//递归实现 
double tencent(int n)//要返回double类型，不然溢出 
{
	if (n == 1)
	{
		printf("第%d阶结束递归:共有1种走法\n", n);

		dTemp = 1.0;//return 1 不能这样写，溢出 
	}
	else if (n == 2)
	{
		printf("第%d阶结束递归:共有2种走法\n", n);
		dTemp = 2.0;//return 2 不能这样写，溢出 
	}
	else
	{
		int temp = n;
		printf("进入递归第%d次:第%d台阶走法=第%d台阶走法+第%d台阶走法;此时n=%d\n", z++, n, temp - 1, temp - 2, temp);
		dTemp = tencent(n - 1) + tencent(n - 2);
		printf("依次返回第%d次递归：共有 %2.0f 种走法\n", --z, dTemp);
	}
	return dTemp;
}
//for循环实现
int For(int n)
{
	int n1 = 1;
	int n2 = 2;
	int n3;
	for (int i = 0; i < n; i++)
	{
		n3 = n1 + n2;
		n1 = n2;//向前移动,n1等于当前n2的值， 
		n2 = n3;//向前移动,n2等于当前n3的值，
	}
	return n3;
}
//数组实现
int Array(int n)
{
	int a[50];
	a[0] = 1;
	a[1] = 2;
	printf("数组实现：\n第1阶走法：a[0] = 1;\n第2阶走法：a[1] = 2;\n");
	for (int i = 2; i < n; i++)//从2开始循环 
	{
		a[i] = a[i - 1] + a[i - 2];
		int temp = i;
		printf("第%d阶走法：a[%d]=a[%d-1]+a[%d-2]=%d\n", temp + 1, i, i, i, a[i]);
	}
	return a[n - 1];
}
void main3()
{
	int n;
	printf("请输入台阶数：");
	scanf("%d", &n);//假设输入的数字是12 
	printf("===递归实现:走到%d阶的可能数是:%2.0f\n", n, tencent(n));//如果是50则溢出大约10分钟才行
	//printf("For 实现:走到%d阶的可能数是:%d\n", n, For(n - 2));//for的10等价于12,n1,n2都被忽略,num从3开始
	//printf("数组实现:走到%d阶的可能数是:%d\n", n, Array(n));
}