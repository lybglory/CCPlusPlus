#define _CRT_SERURE_NO_WARING
#include <iostream>
using namespace std;

int age = 18;

void Test01() {
	int age = 20;
	cout << "local variable age=" << age << endl;
	cout << "global variable age=" << ::age << endl;
}
void main() {
	Test01();
}