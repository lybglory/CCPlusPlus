#define _CRT_SERCURE_NO_WARNINGS
#include <iostream>
using namespace std;
//������
class Animal { virtual void func() = 0; };
class Dog :public Animal {};
//������д����ķ���
class Cat:public Animal{ virtual void func() {} };
class Car {};
void Test01() {
	//1����̬����ת��������������������ת��
	int a = 2021;
	//�﷨��static_cast<Ŀ������>(ԭ����/ԭ����);
	//double d = dynamic_cast<double>(a);

	//2������֮���ת��
	Animal* an = NULL;
	Dog* dog = NULL;
	//��ת����������������ת������ȫ��
	Animal* animal = dynamic_cast<Animal*>(dog);
	//��ת�ӣ�������������ת��������ȫ,ת��ʧ��
	//Dog* dg = dynamic_cast<Dog*>(an);
	//��̬���ǰ�ȫ��
	Animal* aCat = new Cat;
	Cat* cat = dynamic_cast<Cat*>(aCat);
}

void Test02() {
	//����ָ��תָ��
	const int* p = NULL;
	int* pp = const_cast<int*>(p);
	//ָ��ת����ָ��
	const int* ppp = const_cast<const int*>(pp);
	
	//��������const_cast����ָ����߷����ý���ת��
	//const int ca = 10;
	//int in = const_cast<int>(ca);//ת��ʧ��

	int year = 2021;
	int &rfyear = year;
	//����ת���ɳ�����
	const int& crf = const_cast<const int&>(rfyear);

	//���½���ת��������ȫ��������ʹ��
	Animal* an = NULL;
	Car* car = reinterpret_cast<Car*>(an);
}

void main() {
	Test01();
}