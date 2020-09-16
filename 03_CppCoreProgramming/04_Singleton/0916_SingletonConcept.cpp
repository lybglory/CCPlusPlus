#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Dream {
public:
	static Dream *GetDreamInst() {
		return m_dreamInst;
	}
private:
	static Dream *m_dreamInst;
};

Dream *Dream::m_dreamInst = new Dream();

void TestSingle() {
	Dream *d1=Dream::GetDreamInst();
	Dream *d2 = Dream::GetDreamInst();
	if (d1==d2) {
		cout << "d1==d2" << endl;
	}else{
		cout << "d1!=d2" << endl;
	}
}

void main() {
	TestSingle();
}
