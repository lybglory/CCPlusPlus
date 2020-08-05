#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

void TestFunc01(int a = 10, int b = 20) {
	cout << "a + b  = " << a + b << endl;
}
//注意点:
//1. 形参b设置默认参数值，那么后面位置的形参c也需要设置默认参数
void TestFunc02(int a, int b = 10, int c = 10) {}
//2. 如果函数声明和函数定义分开，函数声明设置了默认参数，函数定义不能再设置默认参数
void TestFunc03(int a = 0, int b = 0);
void TestFunc03(int a, int b) {}

void main_0804() {
	//1.如果没有传参数，那么使用默认参数
	TestFunc01();
	//2. 如果传一个参数，那么第二个参数使用默认参数
	TestFunc01(100);
	//3. 如果传入两个参数，那么两个参数都使用我们传入的参数
	TestFunc01(100, 200);
}
