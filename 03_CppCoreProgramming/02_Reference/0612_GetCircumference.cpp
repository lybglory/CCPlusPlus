#define _CRT_SECRUE_NO_WARING
#include <iostream>
using namespace std;
const double pi = 3.14;
class Circle {
	
public:
	int r;
	void SetR(int n) {
		r = n;
	}
	double GetCircumference() {
		return 2*pi * r;
	}
	int getR(){
		return r;
	}

};


void TestCircumference() {
	Circle c1;
	c1.SetR(10);
	cout << "Circumference=" << c1.GetCircumference() << endl;
}

void main_0612() {
	TestCircumference();
}