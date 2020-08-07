#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void Placeholder1(int a, int b, int) {
	//函数内部无法使用占位参数
	cout << "a + b = " << a + b << endl;
}
//占位参数也可以设置默认值
void Placeholder2(int a, int b, int = 20) {
	//函数内部依旧无法使用占位参数
	cout << "a + b = " << a + b << endl;
}
void main_0805() {
	//TestFunc01(10,20);	 //错误调用，占位参数也是参数，必须传参数
	Placeholder1(10, 20, 30);//正确调用
	Placeholder2(10, 20);	 //正确调用
	Placeholder2(10, 20, 30);//正确调用
}

//1. 函数重载条件
namespace A {
	void MyFunc() { cout << "无参数!" << endl; }
	void MyFunc(int a) { cout << "a: " << a << endl; }
	void MyFunc(string b) { cout << "b: " << b << endl; }
	void MyFunc(int a, string b) { cout << "a: " << a << " b:" << b << endl; }
	void MyFunc(string b, int a) { cout << "a: " << a << " b:" << b << endl; }
}
//2.返回值不作为函数重载依据
namespace B {
	void MyFunc(string b, int a) {}
	//int MyFunc(string b, int a){} //无法重载仅按返回值区分的函数
}

void FuncOver(string b) {
	cout << "b: " << b << endl;
}
//函数重载碰上默认参数
void FuncOver(string b, int a = 10) {
	cout << "a: " << a << " b:" << b << endl;
}
void main_0805_2() {
	//FuncOver("hello"); //这时，两个函数都能匹配调用，产生二义性
}
