#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyNumber {
	friend ostream &operator<<(ostream &cout, MyNumber &mynum);
public:
	MyNumber() {
		m_num = 0;
	}
	//ǰ�õ���++
	MyNumber &operator++() {
		//1.++
		m_num++;
		//2.return����
		return *this;
	}


private:
	int m_num;

};

ostream &operator<<(ostream &cout, MyNumber &mynum) {
	cout << mynum.m_num << endl;
	return cout;
}

void Test() {
	MyNumber myNum;
	cout << ++myNum << endl;
}

void main() {
	Test();
}