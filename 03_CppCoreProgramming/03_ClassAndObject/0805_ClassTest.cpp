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
	int type; //��������
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

//��װ���㺬��
//1. ���Ժ���Ϊ�ϳ�һ������
//2. ���ʿ��ƣ���ʵ���ﱾ����Щ���Ժ���Ϊ�ǲ����⿪��
class Person {
	//�˾��е���Ϊ(����)
public:
	void Dese() { cout << "����Ǯ�����ᣬ�����ָߣ��Ͱ��Nɪ!" << endl; }
	//�˵�����(����)
public:
	int mTall; //��ߣ�����������֪��
protected:
	int mMoney; // �ж���Ǯ,ֻ�ܶ�������֪��
private:
	int mAge; //���䣬����������֪��
};

void main_0805_05() {
	Person p;
	p.mTall = 220;
	//p.mMoney ������Ա�ⲿ�޷�����
	//p.mAge ˽�г�Ա�ⲿ�޷�����
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
	//a.mAge; //�޷�����˽�г�Ա
	b.mAge; //�������ⲿ����
}

class AccessLevels {
public:
	//��ֻ�����Խ���ֻ������
	int getReadOnly() { return readOnly; }
	//�Զ�д���Խ��ж�д����
	void setReadWrite(int val) { readWrite = val; }
	int getReadWrite() { return readWrite; }
	//��ֻд���Խ���ֻд����
	void setWriteOnly(int val) { writeOnly = val; }
private:
	int readOnly; //����ֻ������
	int noAccess; //�ⲿ���ɷ���
	int readWrite; //��д����
	int writeOnly; //ֻд����
};
*/
class Person {
public:
	Person() {
		cout << "���캯������!" << endl;
		pName = (char*)malloc(sizeof("Messi"));
		strcpy(pName, "Messi");
		mTall = 150;
		mMoney = 100;
	}
	~Person() {
		cout << "������������!" << endl;
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
