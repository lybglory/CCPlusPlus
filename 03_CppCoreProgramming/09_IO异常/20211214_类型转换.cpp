#define _CRT_SERCURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Animal {};
class Dog :public Animal {};
class Car {};

void Test01() {
	//1、内置数据类型转换
	int a = 2021;
	//语法：static_cast<目标类型>(原对象/原变量);
	double d = static_cast<double>(a);
	cout << typeid(d).name() << endl; //输出：double

	//2、父子之间的转换
	Animal* an = NULL;
	Dog* dog = NULL;
	//子转父，向上数据类型转换，安全的
	Animal* animal = static_cast<Animal*>(dog);
	//父转子，向下数据类型转换，不安全
	Dog* dg = static_cast<Dog*>(an);
}



void main() {
	Test01();
}