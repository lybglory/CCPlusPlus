#define _CRT_SECRUE_NO_WARING
#include <iostream>
using namespace std;

inline int GetSum(int x, int y);
inline int GetSum(int x,int y) {
	return x + y;
}

void TestInline() {
	int sum = GetSum(30,1992);
	cout << "sum=" << sum << endl;
}

void main() {
	TestInline();
}