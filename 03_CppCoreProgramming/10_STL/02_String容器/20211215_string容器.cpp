#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>//��׼�㷨ͷ�ļ�
#include <vector>
using namespace std;

void test01()
{
	string str;
	string str2 = "�ڼҶ׵�2��";
	string str3(str2);
	string str4(2, 'L');
	cout << "str ="  << str << endl;
	cout << "str2 =" << str2 << endl;
	cout << "str3 =" << str3 << endl;
	cout << "str4 =" << str4 << endl;
}

void test02() {
	string str;
	str.assign("2021/12/15");
	cout << "str=" << str << endl;
	//ǰ4���ַ���ֵ����ǰ�ַ�
	str.assign("fucking day", 4);
	cout << "str=" << str << endl;
	//���±�4��ʼ����ֵ3���ַ�����ǰ�ַ���
	str.assign("fucking day", 4,3);
	cout << "str=" << str << endl;
}

void test03() {
	string str;
	str.assign("2021/12/15");
	try{
		//cout << str[100] << endl;
		//ʹ��at���Բ����쳣��ʹ��[]����ֱ�ӱ���
		cout << str.at(100) << endl;
	}
	catch (out_of_range& e){
		cout << e.what() << endl;
	}
	catch (...){
		cout << "�쳣����" << endl;
	}
}

void test04()
{
	//ƴ��
	string str1 = "����";
	string str2 = "��2021/12/15";
	str1 += str2;
	cout << str1 << endl;
	str1.append("�Ǳ��õĵڶ���");
	cout << str1 << endl;

	//����
	string str3 = "Its a dark day";
	int pos = str3.find("dark");
	//rfind �Ǵ����������
	if (pos == -1){
		cout << "δ�ҵ��ַ���" << endl;
	}
	else{
		cout << "�ҵ����ַ�����λ��Ϊ:" << pos << endl;
	}

	//�滻
	//string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
	str3.replace(6, 4, "lucky");
	cout << str3 << endl;
}

void test06()
{
	//�Ӵ�
	//string substr(int pos = 0, int n = npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���

	//string str = "abcdef";

 //   string subStr =	str.substr(0, 3);

	//cout << subStr << endl;


	string email = "binbin@sina.com";
	int pos = email.find("@"); 
	string userName = email.substr(0, pos);
	cout << userName << endl;

}

void test07() {
	string str = "www.baidu.com.cn";
	//�� www  baidu  com  cn ���ʽ�ȡ�� vector������
	vector<string> v;
	int pos = -1;
	int index = 0;
	while (true) {
		//��ָ��λ�ÿ�ʼ����"."���ֵ�λ��
		pos = str.find(".", index);
		if (pos == -1) {
			//��cn��ȡ��������������-���ҵ���ʼλ��
			string temp = str.substr(index, str.size()-index);
			cout << temp << "��ʼλ��:" << index << ";��ȡ����" << str.size() - index << endl;
			v.push_back(temp);
			break;
		}
		string temp = str.substr(index, pos-index);
		v.push_back(temp);
		cout <<temp<<"��ʼλ��:"<<index<<";λ��:" << pos << ";��ȡ����" << pos - index << endl;
		index = pos + 1;
	}
	for (vector<string>::iterator vs = v.begin(); vs !=v.end(); vs++){
		cout << *vs << endl;
	}


}
void test08() {
	string str = "love";
	str.insert(1, "o");	//����
	cout << str << endl;	//loove
	str.erase(1, 1);		//ɾ��
	cout << str << endl;
}

void doWork(string str)
{
	cout << str << endl;
}
void doWork2(const char* str)
{
	cout << str << endl;
}
//3.1.2.9 string��c-style�ַ���ת��
void test09()
{
	const char* str = "fucking C++";
	//const char * תΪ string
	string s(str);
	cout << str << endl;
	//string תΪ const char *
	const char* str2 = s.c_str();
	cout << str2 << endl;
	//const char * ������ʽ����ת��Ϊ  string
	doWork(str2);
	//string ��������ʽ����ת��Ϊ  const char* 
	//doWork2(s);
}
void main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test06();
	//test07();
	//test08();
	test09();
}