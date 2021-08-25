#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	int m_member;
	int m_sex;
private:
	int m_age;
};

class Student:public Base
{
public:
	int m_Id;

private:

};
class Empty {};
void main() {
	cout << "sizeof(Student)=" << sizeof(Student) << endl;
	cout << "sizeof(Empty)=" << sizeof(Empty) << endl;
}