#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void ifSelect() {
	int a = 1;
	int b = 2;

	if (a > b)
	{
		printf("a>b,a=%d,b=%d\n", a, b);
	}
	else {
		printf("a<b,a=%d,b=%d\n", a,b);
	}
}

void ifElseIfElse() {
	unsigned int a;
	scanf("%u", &a);

	if (a < 10)
	{
		printf("个位\n");
	}
	else if (a < 100)
	{
		printf("十位\n");
	}
	else if (a < 1000)
	{
		printf("百位\n");
	}
	else
	{
		printf("很大\n");
	}

}

void SanMuMatch() {
	int year = 0;
	printf("please input year:");
	scanf("%d",&year);
	printf(year >2018?"2019年":"2018年");
}

void WhileFunc() {
	int a = 20;
	while (a > 10)
	{
		scanf("%d", &a);
		printf("a = %d\n", a);
	}
}
void WhileFunc1() {
	int num = 1;
	int sum = 0;
	while (num<=100) {
		sum += num;
		num++;
	}
	printf("sum=%d",sum);//sum=5050
}

void DoWhileFunc() {
	int a = 10;
	do
	{
		printf("a = %d\n", a);
		a++;
	} while (a < 10);
	printf("======\n");
	int b = 10;
	while (b<10) {
		printf("b = %d\n", b);
		b++;
	}
}
/*
#####
 ####
  ###
   ##
    #
*/
void ForFunc() {
	//int n = 5;
	for (int i = 0; i < 5; i++)
	{	//首次进入嵌套，i=0,j=0,判断条件需要<=才会执行
		for (int j = 0; j <= i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
	printf("========\n");
	//外层循环，控制行数
	for (int i = 0; i < 5; i++)
	{	//内层循环控制每列的个数
		for (int j = 0; j < 5; j++)
		{	//首次for循环嵌套,第一行，需要打印5个#,才会跳出第一层for循环
			//第一次：i=0；j=0 .当j=4，已经打印5个#，当j=5,不满足条件,跳出内层循环
			//第二次：跳出内层循环，i=1，
			if (j>=i) {
				//
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void PrintfZhiShu() {
	int m, n;
	//让这个整数从2开始除，除到自己的前一位
	//质数：除了1以外，只能被1和本身整除的数
	for (m = 2; m <= 100; m++)
	{	
		//1、当m=2;n=2;进入内层for循环，判断m % n等于0，跳出循环。
		//	判断外层循环里的if条件，发现是自己本身数字，是质数,打印输出，m++
		//2、当m=3;n=2，不会进入内层if判断3%2，n++，n=3之后跳出，
		//	进入外层里的if判断，m==n，是质数，打印输出,m++
		//3、当m=4，n=2，进入内层if判断4%2，跳出内层循环，
		//	判断外层if，m和n不相等，不是质数
		//4、当m=5,n=2,不会进入内层if判断5%2,5%3,5%4，n++，n=5之后跳出
		// 判断外层if，m=n=5，不是质数,打印输出,m++
		for (n = 2; n < m; n++)
		{
			//m能够整除 除1以外的某个数n，一定不是质数
			if (m % n == 0)//不是质数
			{	//这数字之前数字全部全部整除2完，都没有质数
				//跳出
				break;
			}
		}
		
		//判断n是否是其本身m,如果是，即为质数
		if (m == n) {
			//只输出是质数
			printf("%d; ", m);
		}
	}
}


void ContinueWhile() {
	// while continue实现计算1到100(含)之间的，除了能被7整除之外所有整数的和
	int i = 1;
	int sum = 0;
	int sum7 = 0;
	while (i<=100) {
		if (i%7==0) {
			//能被7整除的数，不进行累加，跳过循环，继续下一次循环
			//i需要+1
			i++;
			continue;
		}
		//之和累加完了，i同样需要进行+1
		sum += i;
		i++;
	}
	printf("sum=%d", sum);
}

void main() {
	//ifElseIfElse();
	//SanMuMatch();
	//DoWhileFunc();
	//ForFunc();
	//PrintfZhiShu();
	ContinueWhile();
}