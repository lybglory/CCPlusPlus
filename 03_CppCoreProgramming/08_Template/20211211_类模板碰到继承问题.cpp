#define _CRT_SERCURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
template <class F>
class RAM {
public:
	F m_num;
};

//����Ҫָ���������е�T�������ͣ����ܸ���������ڴ�
class Kingston :public RAM<int> {
public:

};

template<class S,class F>
class Intel :public RAM<F> {
public:
	Intel() {
		cout << typeid(S).name() << endl;
		cout << typeid(F).name() << endl;
	}
	S m_price;
};

void Test01() {
	Intel< double,int> intel;
	intel.m_price = 99.9;
	intel.m_num = 999;

}

template <typename Tname, typename Tage>
class Person {
public:
	//��ģ���Ա������������������ʵ��
	Person(Tname name, Tage age);
	void ShowInfo();
	Tname m_name;
	Tage m_age;

};
//����ʵ���вι�
template <typename Tname, typename Tage>
Person<Tname,Tage>::Person(Tname name,Tage age) {
	m_name = name;
	m_age = age;
}
//����ʵ�ֺ���
template <typename Tname, typename Tage>
void Person<Tname,Tage>::ShowInfo() {
	cout << m_name << ";" << m_age << endl;
}

void main() {
	//Test01();
	Person<string,int> p("Messi",32 );
	p.ShowInfo();
}