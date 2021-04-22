#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "OverrideLeft.h"
using namespace std;

ostream& operator<<(ostream &cout,Person p) {
	cout <<"age="<< p.m_age <<";id="<<p.m_ID<< endl;
	return cout;
}

void Test01() {
	Person p1(30, 2021);
	cout << p1 << endl;

}
void main() {
	Test01();
}