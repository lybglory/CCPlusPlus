#define _CRT_SERCURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Animal {};
class Dog :public Animal {};
class Car {};

void Test01() {
	//1��������������ת��
	int a = 2021;
	//�﷨��static_cast<Ŀ������>(ԭ����/ԭ����);
	double d = static_cast<double>(a);
	cout << typeid(d).name() << endl; //�����double

	//2������֮���ת��
	Animal* an = NULL;
	Dog* dog = NULL;
	//��ת����������������ת������ȫ��
	Animal* animal = static_cast<Animal*>(dog);
	//��ת�ӣ�������������ת��������ȫ
	Dog* dg = static_cast<Dog*>(an);
}



void main() {
	Test01();
}