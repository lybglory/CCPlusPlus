#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

void TestFunc01(int a = 10, int b = 20) {
	cout << "a + b  = " << a + b << endl;
}
//ע���:
//1. �β�b����Ĭ�ϲ���ֵ����ô����λ�õ��β�cҲ��Ҫ����Ĭ�ϲ���
void TestFunc02(int a, int b = 10, int c = 10) {}
//2. ������������ͺ�������ֿ�����������������Ĭ�ϲ������������岻��������Ĭ�ϲ���
void TestFunc03(int a = 0, int b = 0);
void TestFunc03(int a, int b) {}

void main_0804() {
	//1.���û�д���������ôʹ��Ĭ�ϲ���
	TestFunc01();
	//2. �����һ����������ô�ڶ�������ʹ��Ĭ�ϲ���
	TestFunc01(100);
	//3. �������������������ô����������ʹ�����Ǵ���Ĳ���
	TestFunc01(100, 200);
}
