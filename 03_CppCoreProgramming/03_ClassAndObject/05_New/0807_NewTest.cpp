#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
class Person {
public:
	Person() {
		mAge = 20;
		pName = (char *)malloc(strlen("Messi") + 1);
		strcpy(pName, "Messi");
	}
	void Init() {
		mAge = 20;
		pName = (char *)malloc(strlen("Messi") + 1);
		strcpy(pName, "Messi");
		cout << "name:" << pName << "	age:" <<mAge<< endl;
	}
	void Clean() {
		if (pName != NULL) {
			free(pName);
		}
	}
public:
	int mAge;
	char* pName;
};
void main() {
	Person *person = (Person *)malloc(sizeof(Person));	//�����ڴ�
	if (person == NULL) {
		return;
	}
	
	person->Init();		//���ó�ʼ������
	person->Clean();	//�������	
	free(person);		//�ͷ�person����



//	Person *person = new Person;
////�൱��:
//	Person *person = (Person *)malloc(sizeof(Person));
//	if (person == NULL) {
//		return;
//	}
//	person->Init(); //���캯��

}
