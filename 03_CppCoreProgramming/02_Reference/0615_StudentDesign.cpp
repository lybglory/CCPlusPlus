#define _CRT_SECRUE_NO_WARING
#include <iostream>
using namespace std;

class Student {
public :
	string name;
	int age;
	void setAge(int stAge) {
		age = stAge;
	}
	int getAGE() {
		return age;
	}
	
	void setName(string stuName) {
		name = stuName;
	}

	string getName() {
		return name;
	}
};

void TestStClass() {
	Student s1;
	s1.setName("Messi");
	s1.setAge(18);
	s1.name = "King";
	cout << "s1.name=" << s1.name << "; age=" << s1.age<< endl;
}

void main_0615() {
	TestStClass();
}