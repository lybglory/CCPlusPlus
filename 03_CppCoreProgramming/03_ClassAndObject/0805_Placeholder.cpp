#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void Placeholder1(int a, int b, int) {
	//�����ڲ��޷�ʹ��ռλ����
	cout << "a + b = " << a + b << endl;
}
//ռλ����Ҳ��������Ĭ��ֵ
void Placeholder2(int a, int b, int = 20) {
	//�����ڲ������޷�ʹ��ռλ����
	cout << "a + b = " << a + b << endl;
}
void main_0805() {
	//TestFunc01(10,20);	 //������ã�ռλ����Ҳ�ǲ��������봫����
	Placeholder1(10, 20, 30);//��ȷ����
	Placeholder2(10, 20);	 //��ȷ����
	Placeholder2(10, 20, 30);//��ȷ����
}

//1. ������������
namespace A {
	void MyFunc() { cout << "�޲���!" << endl; }
	void MyFunc(int a) { cout << "a: " << a << endl; }
	void MyFunc(string b) { cout << "b: " << b << endl; }
	void MyFunc(int a, string b) { cout << "a: " << a << " b:" << b << endl; }
	void MyFunc(string b, int a) { cout << "a: " << a << " b:" << b << endl; }
}
//2.����ֵ����Ϊ������������
namespace B {
	void MyFunc(string b, int a) {}
	//int MyFunc(string b, int a){} //�޷����ؽ�������ֵ���ֵĺ���
}

void FuncOver(string b) {
	cout << "b: " << b << endl;
}
//������������Ĭ�ϲ���
void FuncOver(string b, int a = 10) {
	cout << "a: " << a << " b:" << b << endl;
}
void main_0805_2() {
	//FuncOver("hello"); //��ʱ��������������ƥ����ã�����������
}
