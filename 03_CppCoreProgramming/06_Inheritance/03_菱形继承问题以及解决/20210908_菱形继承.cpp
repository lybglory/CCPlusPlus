#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//动物类
class Animal
{
public:
	/// <summary>
	/// 动物类年龄
	/// </summary>
	int m_Age;
};

//Animal 类 成为 虚基类
//加上virtual 关键字之后，继承行为成为 虚继承
//羊类
class Sheep : virtual public Animal {};
//驼类
class Camel : virtual public Animal {};
//羊驼类
class Alpaca :public Sheep, public Camel {};

void test01()
{
	//菱形继承第一个问题：从最上面父类继续下来的属性，使用时候有二义性，可以解决，加作用域
	//菱形继承第二个问题：数据有两份相同的，无意义，浪费内存
	Alpaca alp;
	alp.Sheep::m_Age = 100;
	alp.Camel::m_Age = 200;
	alp.m_Age = 300;

	cout << alp.Sheep::m_Age << endl;
	cout << alp.Camel::m_Age << endl;
	cout << alp.m_Age << endl;
}

void test02()
{
	Alpaca alp;
	alp.m_Age = 100;

	//通过Sheep找到偏移量
	//*(int *)&st 找到了vbtable
	cout << "Sheep的偏移量： " << *((int *)*(int *)&alp + 1) << endl;

	//通过Camel找到偏移量
	//*((int *)(&st) + 1) 找到 vbtable
	cout << "Camel的偏移量： " << *((int *)*((int *)(&alp) + 1) + 1) << endl;


	//通过Sheep的偏移量 获取到具体m_Age
	cout << "alp.m_Age = " << *((int *)((char *)&alp + (*((int *)*(int *)&alp + 1)))) << endl;
	cout << "alp.m_Age = " << ((Animal *)((char *)&alp + (*((int *)*(int *)&alp + 1))))->m_Age << endl;
}


void main() {
	//test01();
	test02();
}