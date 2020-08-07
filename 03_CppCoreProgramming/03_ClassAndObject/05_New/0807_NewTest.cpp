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
	Person *person = (Person *)malloc(sizeof(Person));	//分配内存
	if (person == NULL) {
		return;
	}
	
	person->Init();		//调用初始化函数
	person->Clean();	//清理对象	
	free(person);		//释放person对象



//	Person *person = new Person;
////相当于:
//	Person *person = (Person *)malloc(sizeof(Person));
//	if (person == NULL) {
//		return;
//	}
//	person->Init(); //构造函数

}
