#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person {
public:
	Person() {
		cout << "no param constructor!" << endl;
		mAge = 0;
	}
	//�вι��캯��
	Person(int age) {
		cout << "1 param constructor!" << endl;
		mAge = age;
	}
	//�������캯��(���ƹ��캯��) ʹ����һ�������ʼ��������
	Person(const Person& person) {
		cout << "copy constructor!" << endl;
		mAge = person.mAge;
	}
	//��ӡ����
	void PrintPerson() {
		cout << "Age:" << mAge << endl;
	}
private:
	int mAge;
};
//1. �޲ι�����÷�ʽ
void test01() {

	//�����޲ι��캯��
	Person person1;
	person1.PrintPerson();

	//�޲ι��캯��������÷�ʽ
	//Person person2();
	//person2.PrintPerson();
}
//2. �����вι��캯��
void test02() {

	//��һ�� ���ŷ������
	Person person01(100);
	person01.PrintPerson();

	//���ÿ������캯��
	Person person02(person01);
	person02.PrintPerson();

	//�ڶ��� ��������(��ʾ���ù��캯��)
	Person(200); //��������û�����ֵĶ���

	Person person03 = Person(300);
	person03.PrintPerson();

	//ע��: ʹ�����������ʼ���жϵ�����һ�����캯����Ҫ����������Ĳ�������
	Person person06(Person(400)); //�ȼ��� Person person06 = Person(400);
	person06.PrintPerson();

	//������ =�ŷ� ��ʽת��
	Person person04 = 100; //Person person04 =  Person(100)
	person04.PrintPerson();

	//���ÿ�������
	Person person05 = person04; //Person person05 =  Person(person04)
	person05.PrintPerson();
}

class Teacher {
public:
	Teacher() {
		cout << "Ĭ�Ϲ��캯��!" << endl;
	}
	Teacher(const Teacher& teacher) {
		cout << "�������캯��!" << endl;
	}
public:
	int mAge;
};
void main_0805_07() {
	Teacher t1;	
	//Teacher(t1);  //error C2086:��Teacher t1��: �ض���.
				  //��ʱ�ȼ��� Teacher t1;
}
