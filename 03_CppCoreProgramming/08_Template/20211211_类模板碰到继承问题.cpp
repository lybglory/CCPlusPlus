#define _CRT_SERCURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
template <class F>
class RAM {
public:
	F m_num;
};

//必须要指定出父类中的T数据类型，才能给子类分配内存
class Kingston :public RAM<int> {
public:

};

template<class S,class F>
class Intel :public RAM<F> {
public:
	Intel() {
		cout << typeid(S).name() << endl;
		cout << typeid(F).name() << endl;
	}
	S m_price;
};

void Test01() {
	Intel< double,int> intel;
	intel.m_price = 99.9;
	intel.m_num = 999;

}

template <typename Tname, typename Tage>
class Person {
public:
	//类模板成员函数类内声明，类外实现
	Person(Tname name, Tage age);
	void ShowInfo();
	Tname m_name;
	Tage m_age;

};
//类外实现有参构
template <typename Tname, typename Tage>
Person<Tname,Tage>::Person(Tname name,Tage age) {
	m_name = name;
	m_age = age;
}
//类外实现函数
template <typename Tname, typename Tage>
void Person<Tname,Tage>::ShowInfo() {
	cout << m_name << ";" << m_age << endl;
}

void main() {
	//Test01();
	Person<string,int> p("Messi",32 );
	p.ShowInfo();
}