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
void main() {
	Person p1 = { 18,"Chan" };	//2.c++�ж���ṹ���������Ҫ��struct�ؼ���
}