#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person {
public:
	Person() {
		cout << "no param contructor!" << endl;
		mAge = 10;
	}
	Person(int age) {
		cout << "param constructor!" << endl;
		mAge = age;
	}
	Person(const Person& person) {
		cout << "copy constructor!" << endl;
		mAge = person.mAge;
	}
	~Person() {
		cout << "destructor!" << endl;
	}
public:
	int mAge;
};
//1. �ɶ����ʼ���¶���
void CopyFunc01() {

	Person p(10);
	Person p1(p);
	Person p2 = Person(p);
	Person p3 = p; // �൱��Person p2 = Person(p);
}

//2. ���ݵĲ�������ͨ���󣬺�������Ҳ����ͨ���󣬴��ݽ�����ÿ�������
void doBussiness(Person p) {}

void CopyFunc02() {
	Person p(10);
	doBussiness(p);
}

//3. �������ؾֲ�����
Person MyBusiness() {
	Person p(10);
	cout << "�ֲ�p:" << (int*)&p << endl;
	return p;
}
void CopyFunc03() {
	//vs release��qt��û�е��ÿ������캯��
	//vs debug�µ���һ�ο������캯��
	Person p = MyBusiness();
	cout << "�ֲ�p:" << (int*)&p << endl;
}
void main_0805_07() {
	CopyFunc01();
	CopyFunc02();
	CopyFunc03();
}

//void MyBussiness(Person &_result) {
//	_result.X:X(); //����PersonĬ�Ͽ������캯��
//	//.....��_result���д���
//	return;
//}
//int main() {
//	Person p; //����ֻ����ռ䣬����ʼ��
//	MyBussiness(p);
//}
