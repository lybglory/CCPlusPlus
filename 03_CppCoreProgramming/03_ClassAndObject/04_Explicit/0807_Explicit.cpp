#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class MyString
{
public:

	explicit MyString(int len)
	{
		cout << "MyString�вι��캯��(int  )����" << endl;
	}

	MyString(char* str)
	{
		cout << "MyString�вι��캯��(char * )����" << endl;
	}

};

void test01()
{
	/*MyString str = "abcde";
	MyString str2("abcde");
	MyString str3 = MyString("abcde");*/

	//MyString str4 = 10; // ���˻���Ϊ��  �ַ�����  "10"  Ҳ���˻���Ϊ�ַ�������Ϊ10
	//Ϊ�˷�ֹ����д���������ùؼ��� explicit

	MyString str5(10);

	MyString str6 = MyString(10);


}

void main_0807_00() {}