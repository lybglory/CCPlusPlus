#define _CRT_SERURE_NO_WARING
#include <iostream>
using namespace std;
#include <string.h>

struct Person {
	int age;
	string name;
	void ShowAge(int age) {		//1. �ṹ���м����Զ����Ա������Ҳ���Զ����Ա����
		cout << age << endl;
	}
};


void TestStruct() {
	Person p1 = { 18,"Chan" };	//2.c++�ж���ṹ���������Ҫ��struct�ؼ���
}

void TestTernary() {
	int a = 10;
	int b = 20;
	printf("ret:%d\n", a > b ? a : b);

	cout << "b:" << b << endl;
	//���ص�����ֵ������������
	(a > b ? a : b) = 100;		//���ص�����ֵ������������
	cout << "b:" << b << endl;

}
void main() {
	//TestStruct();
	TestTernary();
}