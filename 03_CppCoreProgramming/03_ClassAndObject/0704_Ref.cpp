#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

void TestRef() {
	//1. �����������÷���һ
	typedef int ArrRef[10];
	int arr[10];
	ArrRef &aRef = arr;
	for (int i = 0; i < 10; i++) {
		aRef[i] = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	//2. �����������÷�����
	int(&f)[10] = arr;
	for (int i = 0; i < 10; i++) {
		f[i] = i + 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//ֵ����
void ValueSwap(int m, int n) {
	int temp = m;
	m = n;
	n = temp;
}
//��ַ����
void PointerSwap(int *m, int *n) {
	int temp = *m;
	*m = *n;
	*n = temp;
}
//���ô���
void ReferenceSwap(int &m, int &n) {
	int temp = m;
	m = n;
	n = temp;
}
void TestFunc() {
	int a = 10;
	int b = 20;
	//ֵ����
	ValueSwap(a, b);
	cout << "a:" << a << " b:" << b << endl;
	//��ַ����
	PointerSwap(&a, &b);
	cout << "a:" << a << " b:" << b << endl;
	//���ô���
	ReferenceSwap(a, b);
	cout << "a:" << a << " b:" << b << endl;
}


void main_0704_01() {
	//TestRef();
	TestFunc();
}

//���ؾֲ���������
int &TestFun01() {
	int a = 10; //�ֲ�����
	return a;
}
//���ؾ�̬��������
int &TestFunc02() {
	static int a = 20;
	cout << "static int a : " << a << endl;
	return a;
}
void main_0704_02() {
	//���ܷ��ؾֲ�����������
	int &ret01 = TestFun01();
	//�����������ֵ����ô���뷵������
	TestFunc02();
	TestFunc02() = 100;
	TestFunc02();
}
#define COMPARE(x,y) ((x) < (y) ? (x) : (y))
int Compare(int x, int y) {
	return x < y ? x : y;
}
void MacroFunc() {
	int a = 1;
	int b = 3;
	//cout << "COMPARE(++a, b):" << COMPARE(++a, b) << endl; // 3
	cout << "Compare(int x,int y):" << Compare(++a, b) << endl; //2
}
