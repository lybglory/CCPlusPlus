#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class People {
public:
	People() {
		cout << "People默认构造" << endl;
	}
	~People() {
		cout << "People析构" << endl;
	}
	int m_member;
	int m_sex;
private:
	int m_age;
};

class Student:public People
{
public:
	Student() {
		cout << "Student默认构造" << endl;
	}
	~Student() {
		cout << "Student析构" << endl;
	}
	int m_Id;
};

class Worker :public People
{
public:
	Worker() {
		cout << "Worker默认构造" << endl;
	}
	~Worker() {
		cout << "Worker析构" << endl;
	}
	int m_salary;
};

class Empty {};
void test01() {
	cout << "sizeof(Empty)=" << sizeof(Empty) << endl;
	cout << "sizeof(People)=" << sizeof(People) << endl;
	cout << "sizeof(Student)=" << sizeof(Student) << endl;
	cout << "sizeof(Worker)=" << sizeof(Worker) << endl;
}

void test02() {
	People p1;
	//Student s1;
	//Worker w1;
}
void main() {
	//test01();
	test02();
}