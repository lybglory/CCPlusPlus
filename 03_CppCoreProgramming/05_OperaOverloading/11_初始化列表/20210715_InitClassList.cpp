#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class XiaoMi {
public:
	XiaoMi() { 
		cout << "XiaoMi默认无参构造" << endl; 
	}
	XiaoMi(int price) {
		m_price = price;
		cout << "XiaoMi构造;m_price=" << m_price << endl;
	}
	~XiaoMi() {
		cout << "XiaoMi虚构"  << endl;
	}
private:
	int m_price;
};

class Apple {
public:
	Apple() {
		cout << "Apple默认无参构造" << endl;
	}
	Apple(int price) {
		m_price = price;
		cout << "Apple构造;m_price=" << m_price << endl;
	}
	~Apple() {
		cout << "Apple虚构" << endl;
	}
private:
	int m_price;
};
class MakeMoblie {
public:
	//初始化列表
	MakeMoblie(int m1,int m2):m_xiaomi(m1),m_apple(m2) {
		cout << "MakeMoblie构造" << endl;
	}
	~MakeMoblie() {
		cout << "MakeMoblie虚构" << endl;
	}
private:
	XiaoMi m_xiaomi;
	Apple m_apple;
};

void Test() {
	MakeMoblie mk(2500,3000);
}

void main() {
	Test();
}
