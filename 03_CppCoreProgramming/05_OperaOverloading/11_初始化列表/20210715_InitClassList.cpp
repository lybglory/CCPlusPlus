#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class XiaoMi {
public:
	XiaoMi() { 
		cout << "XiaoMiĬ���޲ι���" << endl; 
	}
	XiaoMi(int price) {
		m_price = price;
		cout << "XiaoMi����;m_price=" << m_price << endl;
	}
	~XiaoMi() {
		cout << "XiaoMi�鹹"  << endl;
	}
private:
	int m_price;
};

class Apple {
public:
	Apple() {
		cout << "AppleĬ���޲ι���" << endl;
	}
	Apple(int price) {
		m_price = price;
		cout << "Apple����;m_price=" << m_price << endl;
	}
	~Apple() {
		cout << "Apple�鹹" << endl;
	}
private:
	int m_price;
};
class MakeMoblie {
public:
	//��ʼ���б�
	MakeMoblie(int m1,int m2):m_xiaomi(m1),m_apple(m2) {
		cout << "MakeMoblie����" << endl;
	}
	~MakeMoblie() {
		cout << "MakeMoblie�鹹" << endl;
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
