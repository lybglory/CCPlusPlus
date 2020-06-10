#define _CRT_SERURE_NO_WARING
#include <iostream>
using namespace std;
#include <string.h>

struct Person {
	int age;
	string name;
	void ShowAge(int age) {		//1. 结构体中即可以定义成员变量，也可以定义成员函数
		cout << age << endl;
	}
};
void main() {
	Person p1 = { 18,"Chan" };	//2.c++中定义结构体变量不需要加struct关键字
}