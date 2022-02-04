#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>	//vector����ͷ�ļ�
#include <algorithm>//��׼�㷨ͷ�ļ�
using namespace std;
void Test01() {
	//ԭ��ָ��Ҳ�ǵ�����
	int intArr[] = { 2017,2018,2019,2020,2021 };
	int* p = intArr;
	int len = sizeof(intArr) / sizeof(int);
	for (int i = 0; i < len; i++){
		cout << *(p++)<<endl;
	}
}

void PFuncPrintf(int v) {
	cout << v <<" ";
}
void Test02() {
	//����vector����ͷ�ļ���
	//����һ��vector�����������д��Ԫ��������int����
	vector<int> v;
	for (int i = 0; i < 5; i++){
		//β������
		v.push_back(2017+i);
	}

	//����Ԫ��
	//v.begin() ��ʼ��������ָ�������е�һ������
	vector<int>::iterator vi_begin = v.begin();
	//v.end()��������������ָ��������������һ��Ԫ�ص���һ��λ��
	vector<int>::iterator vi_end = v.end();
	
	//��������1��
	while (vi_begin!=vi_end)
	{
		cout << *(vi_begin++) << " ";
	}
	cout << endl;
	//��������2��
	for (vector<int>::iterator vi=v.begin(); vi!=v.end(); vi++){
		cout << *vi<<" ";
	}
	cout << endl;
	//��������3��for_each�����׼�㷨ͷ�ļ�<algorithm>
	//for_each(��ʼ������, ���������, ����ָ��(�ص�����));
	for_each(v.begin(), v.end(), PFuncPrintf);
	
}
/*
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector &vec);//�������캯����

*/
void Test03() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		//β������
		v.push_back(2017 + i);
	}
	vector<int> v2(v.begin(), v.end());
	vector<int> v3(1, 2016);
	//����Ԫ��
	for_each(v2.begin(), v2.end(), PFuncPrintf);
	cout << endl;
	for_each(v3.begin(), v3.end(), PFuncPrintf);

	vector<int> v4;
	v4.assign(v.begin(), v.end());
	cout << endl;
	for_each(v4.begin(), v4.end(), PFuncPrintf);
	v3.swap(v4);
	cout << endl;
	for_each(v4.begin(), v4.end(), PFuncPrintf);
}
/*
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();//����������
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
*/
void Test04() {
	vector<int> v;
	v.push_back(2021);
	v.push_back(2020);
	v.push_back(2019);

	if (v.empty()) {
		cout << "v����Ϊ��" << endl;
	}
	else {
		cout << "v������С��"<<v.size() << endl;
	}
	//����ָ�������ĳ���Ϊ5,�䳤����Ĭ��ֵ���
	v.resize(5,2012);
	for_each(v.begin(), v.end(), PFuncPrintf);
}
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Test05() {
	vector<int>v;
	v.push_back(2019);
	v.push_back(2020);
	v.push_back(2021);

	v.insert(v.begin(), 2012);
	printVector(v);

	v.push_back(2013);
	printVector(v);
	//ɾ�����һ��Ԫ��
	v.pop_back();
	printVector(v);
	//������������ʵλ�õ�Ԫ��
	v.erase(v.begin());
	printVector(v);

	//v.erase(v.begin(), v.end()); �ȼ���  v.clear();
	v.clear();
	//v.erase(v.begin(), v.end());
	printVector(v);
}

void Test06() {
	//����1  ����swap�����ڴ�
	vector<int>v;
	for (int i = 0; i < 100000; i++){
		v.push_back(i);
	}
	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;

	v.resize(3);

	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;

	//����swap�����ڴ�,�������������v����
	vector<int>(v).swap(v);

	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;
}
//���� ���� reserve Ԥ���ռ�
void Test07(){
	vector<int> v;
	v.reserve(100000);
	int* p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//��̬���ӿռ�
		if (p!=&v[0]) {
			p = &v[0];
			num++;	 //��¼�ۼƶ�̬���ӿռ�Ĵ���
		}
	}
	cout << "num = " << num << endl;
}

//�Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void Test08() {
	//��������Զ�����������
	cout << "�Զ�����������" << endl;
	vector<Person> vp;
	Person p1("Mei", 31);
	Person p2("Lian", 30);
	Person p3("Juan", 30);
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	for (vector<Person>::iterator  it=vp.begin(); it!=vp.end(); it++){
		cout << (*it).m_Name << ";" << (*it).m_Age << endl;
	}
	//��������Զ�����������ָ��
	cout << "�Զ�����������ָ��" << endl;
	vector<Person*> pvp;
	pvp.push_back(&p1);
	pvp.push_back(&p2);
	pvp.push_back(&p3);
	for (vector<Person*>::iterator pit = pvp.begin(); pit != pvp.end(); pit++) {
		cout << (*pit)->m_Name << ";" << (*pit)->m_Age << endl;
	}
}

void Test09(){
	//������װС����
	vector< vector<int> > vvi;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	v1.push_back(2021);
	v2.push_back(2020);
	v3.push_back(2019);
	//С����װ�������
	vvi.push_back(v1);
	vvi.push_back(v2);
	vvi.push_back(v3);
	for (vector<vector<int>>::iterator iit = vvi.begin(); iit!=vvi.end(); iit++){
		//*iit --> vector<int>
		for (vector<int>::iterator it = (*iit).begin(); it !=(*iit).end(); it++){
			cout << (*it) << " ";
		}
		cout << endl;
	}
}
void main() {
	//Test01();
	//Test02();
	//Test03();
	//Test04();
	//Test05();
	//Test06();
	//Test07();
	//Test08();
	Test09();
}


