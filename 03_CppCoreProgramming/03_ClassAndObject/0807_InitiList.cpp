#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person {
public:
#if 0
	//��ͳ��ʽ��ʼ��
	Person(int a, int b, int c) {
		mA = a;
		mB = b;
		mC = c;
	}
#endif
	//��ʼ���б�ʽ��ʼ��
	Person(int a, int b, int c) :mA(a), mB(b), mC(c) {
	
	}
	void PrintPerson() {
		cout << "mA:" << mA << endl;
		cout << "mB:" << mB << endl;
		cout << "mC:" << mC << endl;
	}
private:
	int mA;
	int mB;
	int mC;
};
