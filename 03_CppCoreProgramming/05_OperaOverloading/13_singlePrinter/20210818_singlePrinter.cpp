#define _CRT_SECURE_NO_WARNINGS 
#include<iostream> 
using namespace std; 
#include <string>
class Printer {	//打印机类
public:
	static Printer *getInstance() {
		return singlePrinter;
	}

	void printTest(string text) {
		cout << text << endl;
		m_Count++;
	}

	int m_Count; // 统计打印次数

private:
	Printer() { m_Count = 0; };
	Printer(const Printer &) {};
	static Printer *singlePrinter;
};

Printer *Printer::singlePrinter = new Printer;

void main() {
	Printer *p1 = Printer::getInstance();

	p1->printTest("入职申请");
	p1->printTest("旅游申请");
	p1->printTest("升职申请");
	p1->printTest("离职申请");
	cout << "打印机使用次数为： " << p1->m_Count << endl;

	Printer *p2 = Printer::getInstance();
	p2->printTest("调休申请");
	cout << "打印机使用次数为： " << p1->m_Count << endl;

}
