#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person {
public:
	Person() {}
	/// <summary>
	/// 有参构造
	/// </summary>
	/// <param name="p"></param>
	Person(const char *name) {
		cout << "有参构造调用" << endl;
		this->m_name = new char[strlen(name) + 1];
		strcpy(this->m_name, name);
	}

	/// <summary>
	/// 拷贝构造
	/// </summary>
	/// <param name="name"></param>
	Person(const Person &p) {
		cout << "有参构造调用" << endl;
		this->m_name = new char[strlen(p.m_name) + 1];
		strcpy(this->m_name, p.m_name);
	}

	char *m_name;

	~Person() {
		cout << "虚构函数调用" << endl;
	}
};


void Test() {
	Person p1("Messi");
	Person p2("JP");
	//p1 = p2;
	Person p3(p1);
	p3 = p2 = p1;
	
	cout << "p1.name="<<p1.m_name <<"; p2.name="<<p2.m_name<< "; p3.name="<<p3.m_name<<endl;
	
}

void main() {
	Test();
}