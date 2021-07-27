#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Person {
public:
	//1.
	Person(int age) {
		this->age = age;
		cout << "this->age="<<this->age << endl;
	}
	//2.
	Person& getPerson() {
		cout << "return对象的本身"<<endl;
		return *this;
	}
	int age;
};

void main() {
	Person p1(30);
	p1.getPerson();
}
