#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Animal {
public:

	Animal() {
		cout << "Animal无参的构造函数" << endl;
	}
	virtual void DoSpeack() {
		cout << "动物在说话" << endl;
	}
	//~Animal() {
	//virtual ~Animal() {
	//	cout << "Animal的析构函数" << endl;
	//}
	//纯虚函数
	virtual ~Animal() = 0;
};

Animal:: ~Animal() { }
class Dog :public Animal {
public:
	//vs2019以后版本中，形参不加const会报错。
	Dog(const char *dogName)
	{
		cout << "Dog的有参构造函数调用" << endl;
		this->m_Name = new char[strlen(dogName) + 1];
		strcpy(this->m_Name, dogName);
	}

	//重写父类的方法
	 void DoSpeack() {
		cout << this->m_Name << "Dog在说话" << endl;
	}
	~Dog() {
		cout << "Dog的构函数" << endl;
	}

	char * m_Name;
};

void Test() {
	Animal *AnDog = new Dog("福来");
	AnDog->DoSpeack();
	//如果父类的析构函数不加virtual关键字
	delete AnDog;	
	//如果用多态形式把子类对象的属性创建到堆区上，
	//那么释放父类指针的时候就不会重写子类的析构函数，
	//导致子类对象无法释放。
	//如何解决？
	//父类的析构函数，加上virtual关键
}
void main() {
	Test();
}



