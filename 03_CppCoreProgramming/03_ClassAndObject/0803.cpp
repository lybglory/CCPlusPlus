#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;
#define ADD(x,y) x+y
inline int Add(int x, int y) {
	return x + y;
}
void MacroFunc() {
	int ret1 = ADD(10, 20) * 10; //希望的结果是300
	int ret2 = Add(10, 20) * 10; //希望结果也是300
	cout << "ret1:" << ret1 << endl; //210
	cout << "ret2:" << ret2 << endl; //300
}
void main() {
	MacroFunc();
}