#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

class Cube {
private:
	int m_len;
	int m_width;
	int m_hight;
public:
	void SetLength(int len) {
		m_len = len;
	}

	void SetWidth(int width) {
		m_width = width;
	}

	void SetHight(int hight) {
		m_hight = hight;
	}

	int GetLength() {
		return m_len;
	}

	int GetWidth() {
		return m_width;
	}

	int GetHight() {
		return m_hight;
	}

	int GetVolume() {
		return 2 * m_len * m_width + 2 * m_width * m_hight + 2 * m_len * m_hight;
	}

	int GetArea() {
		return m_len * m_width;
	}

	bool IsSameByMem(Cube cb) {
		return m_len == cb.GetLength() &&m_width== cb.GetWidth() &&m_hight== cb.GetHight();
	}
};

bool IsSameCube(Cube &cb1,Cube &cb2) {
	return cb1.GetLength() == cb2.GetLength() && cb1.GetWidth() == cb2.GetWidth() && cb1.GetHight() == cb2.GetHight();
}

void TestCube() {
	Cube c1;
	c1.SetLength(5);
	c1.SetWidth(8);
	c1.SetHight(10);
	cout << "c1.Volume=" << c1.GetVolume() << endl;
	cout << "c1.Area=" << c1.GetArea() << endl;

	Cube c2;
	c2.SetLength(5);
	c2.SetWidth(8);
	c2.SetHight(10);
	cout << "c2.Volume=" << c2.GetVolume() << endl;
	cout << "c2.Area=" << c2.GetArea() << endl;

	bool rect = IsSameCube(c1, c2);
	if (rect) {
		cout << "c1=c2" << endl;
	}
	else {
		cout << "c1 !=c2" << endl;
	}
}

void main() {
	TestCube();
}