#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
typedef struct _Person {
	char name[64];
	int age;
}Person;

typedef struct _Aninal {
	char name[64];
	int age;
	int type; //动物种类
}Animal;

void PersonEat(Person *person) {
	printf("%s is a person!\n", person->name);
}
void AnimalEat(Animal *animal) {
	printf("%s is animal!\n", animal->name);
}

void main_0805_04() {
	Person person;
	strcpy(person.name, "Messi");
	person.age = 30;
	Animal dog;
	strcpy(dog.name, "fulai");
	//AnimalEat(&person);
	AnimalEat(&dog);
}

//封装两层含义
//1. 属性和行为合成一个整体
//2. 访问控制，现实事物本身有些属性和行为是不对外开放
class Person {
	//人具有的行为(函数)
public:
	void Dese() { cout << "我有钱，年轻，个子又高，就爱嘚瑟!" << endl; }
	//人的属性(变量)
public:
	int mTall; //多高，可以让外人知道
protected:
	int mMoney; // 有多少钱,只能儿子孙子知道
private:
	int mAge; //年龄，不想让外人知道
};

void main_0805_05() {
	Person p;
	p.mTall = 220;
	//p.mMoney 保护成员外部无法访问
	//p.mAge 私有成员外部无法访问
	p.Dese();
}

class A {
	int mAge;
};
struct B {
	int mAge;
};

void test() {
	A a;
	B b;
	//a.mAge; //无法访问私有成员
	b.mAge; //可正常外部访问
}

class AccessLevels {
public:
	//对只读属性进行只读访问
	int getReadOnly() { return readOnly; }
	//对读写属性进行读写访问
	void setReadWrite(int val) { readWrite = val; }
	int getReadWrite() { return readWrite; }
	//对只写属性进行只写访问
	void setWriteOnly(int val) { writeOnly = val; }
private:
	int readOnly; //对外只读访问
	int noAccess; //外部不可访问
	int readWrite; //读写访问
	int writeOnly; //只写访问
};
*/
class Person {
public:
	Person() {
		cout << "构造函数调用!" << endl;
		pName = (char*)malloc(sizeof("Messi"));
		strcpy(pName, "Messi");
		mTall = 150;
		mMoney = 100;
	}
	~Person() {
		cout << "析构函数调用!" << endl;
		if (pName != NULL) {
			free(pName);
			pName = NULL;
		}
	}
public:
	char *pName;
	int mTall;
	int mMoney;
};

void main_0805_06() {
	Person person;
	cout << person.pName << person.mTall << person.mMoney << endl;
}
