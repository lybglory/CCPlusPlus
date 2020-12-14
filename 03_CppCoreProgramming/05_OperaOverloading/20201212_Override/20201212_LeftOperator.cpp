#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
class Person {
public:
	int m_age;
	string m_name;
	Person() {
	
	}
	Person(int age,string name) {
		m_age = age;
		m_name = name;
		//cout << "m_age=" << m_age << ";m_name=" << m_name << endl;
	}

	Person operator+(Person &p1) {
		Person temp;
		temp.m_age = p1.m_age + this->m_age;
		return temp;
	}

	//back add
	Person& operator++(int) {

		cout <<this->m_age<< endl;
		this->m_age++;
		return *this;
	}

	//Front add
	Person& operator++() {


		this->m_age++;
		cout << this->m_age << endl;
		return *this;
	}

};
void TestOperatorAdd() {
	Person p1 = Person(30,"Messi");
	Person p2 = Person(30, "CC");
	Person p3;
	p3=p1 + p2;
	cout << p3.m_age << endl;
}

ostream &operator<<(ostream &out, Person &p) {
	cout << "m_age=" << p.m_age << ";m_name=" << p.m_name;
	return out;
}


void TestLeftOper() {
	Person p1 = Person(30, "Messi");
	cout << p1 << endl;
}

void TestBackAdd() {
	Person p1(29,"Messi");
	p1++;
	cout << p1 << endl;
}

void TestFrontAdd() {
	Person p1(1,"Soup");
	cout << "Front add:"<<p1 << endl;
	++p1;
	cout << p1 << endl;
	cout << p1 << endl;
}

class City {
public:
	City(int code,string cname) {
		m_code = new int(code);
		m_name = new string(cname);
	}

	City &operator=(City &c) {
		if (m_code!=NULL) {
			delete m_code;
			m_code = NULL;
		}
		if (m_name != NULL) {
			delete m_name;
			m_name = NULL;
		}
		//deep copy
		m_code = new int(*c.m_code);
		m_name = new string(*c.m_name);
		return *this;
	}

	int *m_code;
	string *m_name;
	~City() {
		if (m_code!=NULL) {
			delete m_code;
			m_code = NULL;
		}
	}

};
void TestAssignment() {

	City c1(1,"Peiking");
	cout << *c1.m_code << endl;
	City c2(2,"Shanghai");
	c2 = c1;
	cout << *c2.m_code<<";"<<*c2.m_name << endl;

}
void main() {
	//TestOperatorAdd();
	//TestLeftOper();
	//TestBackAdd();
	//TestFrontAdd();
	TestAssignment();
}