#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include "MyArray.hpp"

class Person {
public:
	//�������new�ڶ������� �Զ����������ݵ����飬������Ĭ�Ϲ��캯��
	Person() {}
	Person(int age,string name) {
		this->m_age = age;
		this->m_name = name;
	}

	int m_age;
	string m_name;
};


void PrintfIntArr(MyArray<int> &arr) {
	for (int i = 0; i < arr.GetArrLeng(); i++){
			cout << arr[i] << endl;
	}
}
void PrintfPerArr(MyArray<Person>& arr) {
	cout << typeid(arr[0]).name() << endl;
	for (int i = 0; i < arr.GetArrLeng(); i++)
	{
		cout << arr[i].m_name << ";"<<arr[i].m_age << endl;
	}
}

void Test01() {
	MyArray<int> intarr(3);
	intarr.TailInsert(2021);
	intarr.TailInsert(2020);
	intarr.TailInsert(2017);
	PrintfIntArr(intarr);
	cout << "����Ԫ��" << intarr.GetArrLeng() << endl;
	cout << "��������" << intarr.GetArrCapacity() << endl;
}

void Test02() {
	MyArray<Person> arrpr(10);
	Person p1(30,"Lian");
	Person p2(31, "Mei");
	Person p3(30, "Hua");
	arrpr.TailInsert(p1); 
	arrpr.TailInsert(p2);
	arrpr.TailInsert(p3);
	PrintfPerArr(arrpr);
	cout << "����Ԫ��" << arrpr.GetArrLeng() << endl;
	cout << "��������" << arrpr.GetArrCapacity()<< endl;
}

void main() {
	Test01();
	Test02();
}