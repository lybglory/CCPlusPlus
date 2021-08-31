#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Animal {
public:
	 virtual void Speak() {
		cout << "Anmail try to speak" << endl;
	}
};

class Cat :public Animal{
public:
	void Speak() {
		cout << "Cat try to speak" << endl;
	}
};

class Dog :public Animal {
public:
	void Speak() {
		cout << "Dog try to speak" << endl;
	}
};

//父类的引用指向子类对象
void DoSpeak(Animal &a) {
	a.Speak();
}
void test01() {
	Cat c1;
	DoSpeak(c1);
}

void test02() {
	Animal *c1 = new Cat;
	//c1->Speak();
	((void(*)()) (*(int *)*(int *)c1))();
}
void main() {
	//test01();
	test02();
}