#include <iostream>
#include <string>
using namespace std;

template<class T1,class T2>
class Person {
public:
	Person(T1 age, T2 name);
	void ShowInfo();


	T1 m_age;
	T2 m_name;
};

template<class T1, class T2>
Person<T1,T2>::Person(T1 age, T2 name) {
	this->m_age = age;
	this->m_name = name;
}


template<class T1, class T2>
void Person<T1,T2>::ShowInfo() {
	cout << "name:" <<this->m_name << ";age=" << this->m_age << endl;
}

void Test01() {
	Person<int,string> p1(31,"Messi");
	p1.ShowInfo();

}
void main() {
	Test01();
}