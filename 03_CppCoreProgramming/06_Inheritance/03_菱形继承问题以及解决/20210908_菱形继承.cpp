#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//������
class Animal
{
public:
	/// <summary>
	/// ����������
	/// </summary>
	int m_Age;
};

//Animal �� ��Ϊ �����
//����virtual �ؼ���֮�󣬼̳���Ϊ��Ϊ ��̳�
//����
class Sheep : virtual public Animal {};
//����
class Camel : virtual public Animal {};
//������
class Alpaca :public Sheep, public Camel {};

void test01()
{
	//���μ̳е�һ�����⣺�������游��������������ԣ�ʹ��ʱ���ж����ԣ����Խ������������
	//���μ̳еڶ������⣺������������ͬ�ģ������壬�˷��ڴ�
	Alpaca alp;
	alp.Sheep::m_Age = 100;
	alp.Camel::m_Age = 200;
	alp.m_Age = 300;

	cout << alp.Sheep::m_Age << endl;
	cout << alp.Camel::m_Age << endl;
	cout << alp.m_Age << endl;
}

void test02()
{
	Alpaca alp;
	alp.m_Age = 100;

	//ͨ��Sheep�ҵ�ƫ����
	//*(int *)&st �ҵ���vbtable
	cout << "Sheep��ƫ������ " << *((int *)*(int *)&alp + 1) << endl;

	//ͨ��Camel�ҵ�ƫ����
	//*((int *)(&st) + 1) �ҵ� vbtable
	cout << "Camel��ƫ������ " << *((int *)*((int *)(&alp) + 1) + 1) << endl;


	//ͨ��Sheep��ƫ���� ��ȡ������m_Age
	cout << "alp.m_Age = " << *((int *)((char *)&alp + (*((int *)*(int *)&alp + 1)))) << endl;
	cout << "alp.m_Age = " << ((Animal *)((char *)&alp + (*((int *)*(int *)&alp + 1))))->m_Age << endl;
}


void main() {
	//test01();
	test02();
}