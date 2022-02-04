#define _CRT_SERCURE_NO_WARNINGS
#include <iostream>
using namespace std;
//抽象类
class Animal { virtual void func() = 0; };
class Dog :public Animal {};
//子类重写父类的方法
class Cat:public Animal{ virtual void func() {} };
class Car {};
void Test01() {
	//1、动态类型转换不允许内置数据类型转换
	int a = 2021;
	//语法：static_cast<目标类型>(原对象/原变量);
	//double d = dynamic_cast<double>(a);

	//2、父子之间的转换
	Animal* an = NULL;
	Dog* dog = NULL;
	//子转父，向上数据类型转换，安全的
	Animal* animal = dynamic_cast<Animal*>(dog);
	//父转子，向下数据类型转换，不安全,转换失败
	//Dog* dg = dynamic_cast<Dog*>(an);
	//多态总是安全的
	Animal* aCat = new Cat;
	Cat* cat = dynamic_cast<Cat*>(aCat);
}

void Test02() {
	//常量指针转指针
	const int* p = NULL;
	int* pp = const_cast<int*>(p);
	//指针转常量指针
	const int* ppp = const_cast<const int*>(pp);
	
	//不允许用const_cast将非指针或者非引用进行转换
	//const int ca = 10;
	//int in = const_cast<int>(ca);//转换失败

	int year = 2021;
	int &rfyear = year;
	//引用转换成常引用
	const int& crf = const_cast<const int&>(rfyear);

	//重新解释转换，不安全，不建议使用
	Animal* an = NULL;
	Car* car = reinterpret_cast<Car*>(an);
}

void main() {
	Test01();
}