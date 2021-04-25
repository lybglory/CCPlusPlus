#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age) {
		m_age = age;
		cout << "有参构造：m_age="<<m_age << endl;
	};

	void ShowAge() {
		cout << "ShowAge()_age="<<m_age << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
	};

private:
	int m_age;
};


class Smartpt {

public:
	Smartpt(Person *p) {
		cout << "Smartpt有参构造" << endl;
		this->m_person = p;
	}

	Person *operator->() {
		return this->m_person;
	}


	~Smartpt() {
		cout << "~Smartpt()" << endl;
		if (this->m_person != NULL) {
			delete this->m_person;
			this->m_person = NULL;
		}
	}
	Person *m_person;
};



void Test() {
	Person *p = new Person(18);
	p->ShowAge();

	Smartpt smpt(new Person(30));
	smpt->ShowAge();
	
}

void main() {
	Test();
}