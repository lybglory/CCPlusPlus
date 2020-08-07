#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int a)
	{
		cout << "Person的有参构造函数调用" << endl;
	}

	Person(const Person& p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

//1 C 和 C++堆区开辟内存和释放内存区别
// C用 malloc   C++ new 
// malloc --  free
// new   -- delete 
// malloc  free 本质 库函数
// new   delete  本质 运算符
// malloc返回的数据类型  void * 
// new  返回数据类型  创建的对象的指针类型 

void test01()
{
	//new 运算符 也是在堆区开辟内存空间
	Person* p1 = new Person;

	Person* p2 = new Person(10);

	Person* p3 = new Person(*p2);

	//如果想释放new出来的对象 ，利用关键字 delete
	delete p1;
	delete p2;
	delete p3;
}

//2、注意事项
//不要用void *接受new出来的对象 ,原因无法是否
void test02()
{
	void* p = new Person;

	delete p;
}


//3、利用new在堆区开辟数组
void test03()
{
	int* intArray = new int[10];

	char* charArray = new char[100];

	//如果利用new在堆区开辟 自定义类型数据的数组，必须有默认构造函数
	Person* personArray = new Person[10];

	//如果在栈上开辟数组，可以没有默认构造函数
	//Person pArray[2] = { Person(1), Person(2) };

	//delete []personArray;

	delete personArray;
}

void main() {

	//test01();

	//test02();

	test03();
}