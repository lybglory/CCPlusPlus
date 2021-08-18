#define _CRT_SECURE_NO_WARNINGS 
#include<iostream> 
using namespace std; 
#include <string>
class Printer {	//��ӡ����
public:
	static Printer *getInstance() {
		return singlePrinter;
	}

	void printTest(string text) {
		cout << text << endl;
		m_Count++;
	}

	int m_Count; // ͳ�ƴ�ӡ����

private:
	Printer() { m_Count = 0; };
	Printer(const Printer &) {};
	static Printer *singlePrinter;
};

Printer *Printer::singlePrinter = new Printer;

void main() {
	Printer *p1 = Printer::getInstance();

	p1->printTest("��ְ����");
	p1->printTest("��������");
	p1->printTest("��ְ����");
	p1->printTest("��ְ����");
	cout << "��ӡ��ʹ�ô���Ϊ�� " << p1->m_Count << endl;

	Printer *p2 = Printer::getInstance();
	p2->printTest("��������");
	cout << "��ӡ��ʹ�ô���Ϊ�� " << p1->m_Count << endl;

}
