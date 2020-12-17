#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Calulator {
	public:
		virtual int GetResult() {
			return 0;
		}
		int num1;
		int num2;

};

class ClsAdd :public Calulator {
public:

	int GetResult() {
		return num1 + num2;
	}
};
class ClsMinues :public Calulator {
public:
	int GetResult() {
		return num1 - num2;
	}

};

class ClsDiv :public Calulator {
public:
	int GetResult() {
		return num1 / num2;
	}
};
class ClsMult :public Calulator {
public:
	int GetResult() {
		return num1 * num2;
	}

};
void TestVirtual() {
	Calulator *rect=new ClsAdd();
	rect->num1 = 90;
	rect->num2 = 10;
	cout << rect->num1<<"+"<<rect->num2<<"=" <<rect->GetResult() << endl;
	delete rect;

	rect = new ClsMinues();
	rect->num1 = 90;
	rect->num2 = 10;
	cout << rect->num1 << "-" << rect->num2 << "=" << rect->GetResult() << endl;
	delete rect;


	rect = new ClsDiv();
	rect->num1 = 90;
	rect->num2 = 10;
	cout << rect->num1 << "/" << rect->num2 << "=" << rect->GetResult() << endl;
	delete rect;

	rect = new ClsMult();
	rect->num1 = 90;
	rect->num2 = 10;
	cout << rect->num1 << "*" << rect->num2 << "=" << rect->GetResult() << endl;
	delete rect;

}
void main() {
	TestVirtual();
}