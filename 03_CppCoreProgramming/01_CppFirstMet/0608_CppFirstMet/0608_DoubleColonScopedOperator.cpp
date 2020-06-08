#define _CRT_SERURE_NO_WARING
#include <iostream>
using namespace std;
#include "Game1.h"
#include "Game2.h"


int age = 18;

void Test01() {
	int age = 20;
	cout << "local variable age=" << age << endl;
	cout << "global variable age=" << ::age << endl;
}

void Test02() {
	Game2::Attack();
	Game1::Attack();
}

void main() {
	//Test01();
	Test02();
}