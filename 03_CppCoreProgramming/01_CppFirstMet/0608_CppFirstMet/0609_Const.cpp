#define _CRT_SERURE_NO_WARING
#include <iostream>
using namespace std;
#include <string.h>
void ConstTest1() {
	int year = 2020;
	//ʹ�ñ�����ʼ�� const���εľֲ�������
	//������ڴ棬���Լ���޸�const���η��ı���ֵ
	const int cnt_year = year;
	int *p_year = (int *)&cnt_year;
	*p_year = 2019;
	cout << "cnt_year=" << cnt_year << endl;
}

struct Person
{
	string name;
	int age;
};

void ConstTest2() {
	Person p1;
	p1.name = "Messi";
	p1.age = 33;
	cout << "name=" << p1.name << ";age=" << p1.age << endl;
}

void ConstTest3() {
	const Person p1;
	Person *p = (Person*)&p1;
	p->name = "Trump";
	p->age = 75;
	cout << "name=" << p1.name << ";age=" << p1.age << endl;
}
void main_0609() {
	ConstTest1();
	ConstTest2();
 	ConstTest3();
}