#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	Person(char* name, int age)
	{
		//给Person的姓名 开辟堆区
		m_Name = (char*)malloc(strlen(name) + 1);
		strcpy(m_Name, name);

		m_Age = age;
	}
	//自己提供拷贝构造函数 实现深拷贝
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		//m_Name = p.m_Name;  编译器提供的就是这行代码

		m_Name = (char*)malloc(strlen(p.m_Name) + 1);

		strcpy(m_Name, p.m_Name);

	}

	~Person()  //释放在堆区开辟的属性
	{
		cout << "Person析构函数被调用" << endl;
		if (m_Name != NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}

	//姓名
	char* m_Name;
	//年龄
	int m_Age;
};

void test01()
{
	Person p1("Tom", 18);

	cout << "p1的姓名：" << p1.m_Name << " 年龄： " << p1.m_Age << endl;

	Person p2 = p1; //调用拷贝构造函数 初始化 p2对象

	cout << "p2的姓名：" << p2.m_Name << " 年龄： " << p2.m_Age << endl;

}

void main() {

	test01();

	//创建字符数组
	char* pStr = new char[100];
	//创建整型数组
	int* pArr1 = new int[100];
	//创建整型数组并初始化
	int* pArr2 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//释放数组内存
	delete[] pStr;
	delete[] pArr1;
	delete[] pArr2;
}


