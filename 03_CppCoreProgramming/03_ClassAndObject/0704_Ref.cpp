#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

void TestRef() {
	//1. 建立数组引用方法一
	typedef int ArrRef[10];
	int arr[10];
	ArrRef &aRef = arr;
	for (int i = 0; i < 10; i++) {
		aRef[i] = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	//2. 建立数组引用方法二
	int(&f)[10] = arr;
	for (int i = 0; i < 10; i++) {
		f[i] = i + 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//值传递
void ValueSwap(int m, int n) {
	int temp = m;
	m = n;
	n = temp;
}
//地址传递
void PointerSwap(int *m, int *n) {
	int temp = *m;
	*m = *n;
	*n = temp;
}
//引用传递
void ReferenceSwap(int &m, int &n) {
	int temp = m;
	m = n;
	n = temp;
}
void TestFunc() {
	int a = 10;
	int b = 20;
	//值传递
	ValueSwap(a, b);
	cout << "a:" << a << " b:" << b << endl;
	//地址传递
	PointerSwap(&a, &b);
	cout << "a:" << a << " b:" << b << endl;
	//引用传递
	ReferenceSwap(a, b);
	cout << "a:" << a << " b:" << b << endl;
}


void main_0704_01() {
	//TestRef();
	TestFunc();
}

//返回局部变量引用
int &TestFun01() {
	int a = 10; //局部变量
	return a;
}
//返回静态变量引用
int &TestFunc02() {
	static int a = 20;
	cout << "static int a : " << a << endl;
	return a;
}
void main_0704_02() {
	//不能返回局部变量的引用
	int &ret01 = TestFun01();
	//如果函数做左值，那么必须返回引用
	TestFunc02();
	TestFunc02() = 100;
	TestFunc02();
}
#define COMPARE(x,y) ((x) < (y) ? (x) : (y))
int Compare(int x, int y) {
	return x < y ? x : y;
}
void MacroFunc() {
	int a = 1;
	int b = 3;
	//cout << "COMPARE(++a, b):" << COMPARE(++a, b) << endl; // 3
	cout << "Compare(int x,int y):" << Compare(++a, b) << endl; //2
}
