#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Person {
public:
	Person() {
		cout << "Person�޲ι���" << endl;
	}
	Person(int n) {
		cout << "Person�в��޲ι���" << endl;
	}
	~Person() {
		cout << "Person�鹹" << endl;
	}
};

void main() {
	//C���Է�ʽ��malloc������ù��캯��
	Person* p1 = (Person *)malloc(sizeof(Person));
	free(p1);
	cout << "����new����" << endl;
	Person* p2 = new Person();
	delete(p2);
}
