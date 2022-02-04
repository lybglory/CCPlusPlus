#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class People {
public:
	People() {
		m_age = 80;
	}
	void Todo() {
		cout << "People_Todo()" << endl;
	}
	int m_age;
};

class Student :public People
{
public:
	Student() {
		m_age = 18;
	}
	void Todo() {
		cout << "Student_Todo()" << endl;
	}
	int m_age;
};

class Worker :public People
{
public:
	Worker() {
		m_age = 30;
	}
	void Todo() {
		cout << "Worker_Todo()" << endl;
	}
	int m_age;
};

void test01() {
	People p1;
	cout << "p1.m_age=" << p1.m_age << endl;
	Student s1;

	cout <<"s1.m_age="<< s1.m_age << endl;
	cout << "s1.People::m_age=" << s1.People::m_age << endl;
}

void main() {
	test01();
}