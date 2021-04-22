#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#pragma once

class Person {
	friend	ostream &operator<<(ostream &cout, Person p);
public:
	Person(int age, int id);
private:
	int m_age;
	int m_ID;
};
