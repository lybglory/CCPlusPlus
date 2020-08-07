#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(int a)
	{
		cout << "Person���вι��캯������" << endl;
	}

	Person(const Person& p)
	{
		cout << "Person�Ŀ������캯������" << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}
};

//1 C �� C++���������ڴ���ͷ��ڴ�����
// C�� malloc   C++ new 
// malloc --  free
// new   -- delete 
// malloc  free ���� �⺯��
// new   delete  ���� �����
// malloc���ص���������  void * 
// new  ������������  �����Ķ����ָ������ 

void test01()
{
	//new ����� Ҳ���ڶ��������ڴ�ռ�
	Person* p1 = new Person;

	Person* p2 = new Person(10);

	Person* p3 = new Person(*p2);

	//������ͷ�new�����Ķ��� �����ùؼ��� delete
	delete p1;
	delete p2;
	delete p3;
}

//2��ע������
//��Ҫ��void *����new�����Ķ��� ,ԭ���޷��Ƿ�
void test02()
{
	void* p = new Person;

	delete p;
}


//3������new�ڶ�����������
void test03()
{
	int* intArray = new int[10];

	char* charArray = new char[100];

	//�������new�ڶ������� �Զ����������ݵ����飬������Ĭ�Ϲ��캯��
	Person* personArray = new Person[10];

	//�����ջ�Ͽ������飬����û��Ĭ�Ϲ��캯��
	//Person pArray[2] = { Person(1), Person(2) };

	//delete []personArray;

	delete personArray;
}

void main() {

	//test01();

	//test02();

	test03();
}