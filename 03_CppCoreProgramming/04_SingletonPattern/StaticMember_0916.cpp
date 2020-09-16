#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person {
public :
	Person() {
		//Do not initialize static member variables in the constructor
		//m_age = 30;
	}
	static int m_age;
};

int Person::m_age = 30;//≥ı ºªØ

void Access01() {
	cout << "Person::m_age=" << Person::m_age << endl;
}

void Access02() {
	Person p1;
	cout << "p1.m_age=" << p1.m_age << endl;
}
void main() {
	Access01();
	Access02();
}