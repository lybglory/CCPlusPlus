#define _CRT_SECRUE_NO_WARING
#include <iostream>
using namespace std;

void Override(int x,int y,string name) {
	cout << name << endl;
}
void Override(int x, int y) {
	cout << "x="<<x<<";y="<<y << endl;
}

void main0619_02() {
	Override(10,30,"Messi");
	Override(10, 30);
}