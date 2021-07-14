#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyNumber {
	friend ostream &operator<<(ostream &cout, MyNumber mynum);
public:
	MyNumber() {
		m_num = 0;
	}
	//前置递增++
	MyNumber &operator++() {
		//1.++
		m_num++;
		//2.return自身
		return *this;
	}

	//后置++
	MyNumber operator++(int) {
		//1.先保存原有的值
		MyNumber temp = *this;
		//2.再++
		m_num++;
		//3.返回
		return temp;

	}

private:
	int m_num;

};

ostream &operator<<(ostream &cout, MyNumber mynum) {
	cout << mynum.m_num << endl;
	return cout;
}

void Test() {
	MyNumber myNum;
	cout <<"初始值：num="<<myNum << endl;

	cout << "前置++，num="<<++myNum << endl;
	cout << "前置++结果，num=" << myNum << endl;

	cout << "后置++，num=" << myNum++ << endl;
	cout << "后置++结果num="<<myNum << endl;
}

void main() {
	Test(); 
}