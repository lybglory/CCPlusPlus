#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Animal {
public:

	Animal() {
		cout << "Animal�޲εĹ��캯��" << endl;
	}
	virtual void DoSpeack() {
		cout << "������˵��" << endl;
	}
	//~Animal() {
	//virtual ~Animal() {
	//	cout << "Animal����������" << endl;
	//}
	//���麯��
	virtual ~Animal() = 0;
};

Animal:: ~Animal() { }
class Dog :public Animal {
public:
	//vs2019�Ժ�汾�У��ββ���const�ᱨ��
	Dog(const char *dogName)
	{
		cout << "Dog���вι��캯������" << endl;
		this->m_Name = new char[strlen(dogName) + 1];
		strcpy(this->m_Name, dogName);
	}

	//��д����ķ���
	 void DoSpeack() {
		cout << this->m_Name << "Dog��˵��" << endl;
	}
	~Dog() {
		cout << "Dog�Ĺ�����" << endl;
	}

	char * m_Name;
};

void Test() {
	Animal *AnDog = new Dog("����");
	AnDog->DoSpeack();
	//��������������������virtual�ؼ���
	delete AnDog;	
	//����ö�̬��ʽ�������������Դ����������ϣ�
	//��ô�ͷŸ���ָ���ʱ��Ͳ�����д���������������
	//������������޷��ͷš�
	//��ν����
	//�������������������virtual�ؼ�
}
void main() {
	Test();
}



