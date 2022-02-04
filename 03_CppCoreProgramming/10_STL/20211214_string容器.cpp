#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>	//vector容器头文件
#include <algorithm>//标准算法头文件
using namespace std;
void Test01() {
	//原生指针也是迭代器
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
	//引入vector容器头文件，
	//创建一个vector容器，容器中存放元素类型是int类型
	vector<int> v;
	for (int i = 0; i < 5; i++){
		//尾插数据
		v.push_back(2017+i);
	}

	//遍历元素
	//v.begin() 起始迭代器，指向容器中第一个数据
	vector<int>::iterator vi_begin = v.begin();
	//v.end()；结束迭代器，指向的是容器中最后一个元素的下一个位置
	vector<int>::iterator vi_end = v.end();
	
	//遍历方法1：
	while (vi_begin!=vi_end)
	{
		cout << *(vi_begin++) << " ";
	}
	cout << endl;
	//遍历方法2：
	for (vector<int>::iterator vi=v.begin(); vi!=v.end(); vi++){
		cout << *vi<<" ";
	}
	cout << endl;
	//遍历方法3：for_each引入标准算法头文件<algorithm>
	//for_each(起始迭代器, 结算迭代器, 函数指针(回调函数));
	for_each(v.begin(), v.end(), PFuncPrintf);
	
}
/*
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。

*/
void Test03() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		//尾插数据
		v.push_back(2017 + i);
	}
	vector<int> v2(v.begin(), v.end());
	vector<int> v3(1, 2016);
	//遍历元素
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
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
void Test04() {
	vector<int> v;
	v.push_back(2021);
	v.push_back(2020);
	v.push_back(2019);

	if (v.empty()) {
		cout << "v容器为空" << endl;
	}
	else {
		cout << "v容器大小："<<v.size() << endl;
	}
	//重新指定容器的长度为5,变长部分默认值填充
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
	//删除最后一个元素
	v.pop_back();
	printVector(v);
	//擦除迭代器其实位置的元素
	v.erase(v.begin());
	printVector(v);

	//v.erase(v.begin(), v.end()); 等价于  v.clear();
	v.clear();
	//v.erase(v.begin(), v.end());
	printVector(v);
}

void Test06() {
	//案例1  巧用swap收缩内存
	vector<int>v;
	for (int i = 0; i < 100000; i++){
		v.push_back(i);
	}
	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;

	v.resize(3);

	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;

	//巧用swap收缩内存,匿名对象跟容器v交换
	vector<int>(v).swap(v);

	cout << "v.capacity = " << v.capacity() << endl;
	cout << "v.size = " << v.size() << endl;
}
//案例 巧用 reserve 预留空间
void Test07(){
	vector<int> v;
	v.reserve(100000);
	int* p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//动态增加空间
		if (p!=&v[0]) {
			p = &v[0];
			num++;	 //记录累计动态增加空间的次数
		}
	}
	cout << "num = " << num << endl;
}

//自定义数据类型
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
	//容器存放自定义数据类型
	cout << "自定义数据类型" << endl;
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
	//容器存放自定义数据类型指针
	cout << "自定义数据类型指针" << endl;
	vector<Person*> pvp;
	pvp.push_back(&p1);
	pvp.push_back(&p2);
	pvp.push_back(&p3);
	for (vector<Person*>::iterator pit = pvp.begin(); pit != pvp.end(); pit++) {
		cout << (*pit)->m_Name << ";" << (*pit)->m_Age << endl;
	}
}

void Test09(){
	//大容器装小容器
	vector< vector<int> > vvi;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	v1.push_back(2021);
	v2.push_back(2020);
	v3.push_back(2019);
	//小容器装入大容器
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


