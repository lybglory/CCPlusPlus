#define _CRT_SECRUE_NO_WARING
#include <iostream>
using namespace std;
int PlaceholderTest(int a,int) {
	return a + 2020;
}

void main() {
	int rec = PlaceholderTest(10,5);
	cout << "rec=" << rec << endl;
}