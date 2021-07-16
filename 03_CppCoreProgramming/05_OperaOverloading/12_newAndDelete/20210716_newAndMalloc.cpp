#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Person {
public:
	Person() {
		cout << "Person无参构造" << endl;
	}
	Person(int n) {
		cout << "Person有参无参构造" << endl;
	}
	~Person() {
		cout << "Person虚构" << endl;
	}
};

void main() {
	//C语言方式，malloc不会调用构造函数
	Person* p1 = (Person *)malloc(sizeof(Person));
	free(p1);
	cout << "↓↓new↓↓" << endl;
	Person* p2 = new Person();
	delete(p2);
}
