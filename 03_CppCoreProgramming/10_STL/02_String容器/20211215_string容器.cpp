#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>//标准算法头文件
#include <vector>
using namespace std;

void test01()
{
	string str;
	string str2 = "在家蹲第2天";
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
	//前4个字符赋值给当前字符
	str.assign("fucking day", 4);
	cout << "str=" << str << endl;
	//从下标4开始，赋值3个字符给当前字符串
	str.assign("fucking day", 4,3);
	cout << "str=" << str << endl;
}

void test03() {
	string str;
	str.assign("2021/12/15");
	try{
		//cout << str[100] << endl;
		//使用at可以捕获异常，使用[]程序直接崩溃
		cout << str.at(100) << endl;
	}
	catch (out_of_range& e){
		cout << e.what() << endl;
	}
	catch (...){
		cout << "异常捕获" << endl;
	}
}

void test04()
{
	//拼接
	string str1 = "今天";
	string str2 = "是2021/12/15";
	str1 += str2;
	cout << str1 << endl;
	str1.append("是被裁的第二天");
	cout << str1 << endl;

	//查找
	string str3 = "Its a dark day";
	int pos = str3.find("dark");
	//rfind 是从右往左查找
	if (pos == -1){
		cout << "未找到字符串" << endl;
	}
	else{
		cout << "找到了字符串，位置为:" << pos << endl;
	}

	//替换
	//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
	str3.replace(6, 4, "lucky");
	cout << str3 << endl;
}

void test06()
{
	//子串
	//string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

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
	//将 www  baidu  com  cn 单词截取到 vector容器中
	vector<string> v;
	int pos = -1;
	int index = 0;
	while (true) {
		//从指定位置开始查找"."出现的位置
		pos = str.find(".", index);
		if (pos == -1) {
			//把cn截取出来，整个长度-查找的起始位置
			string temp = str.substr(index, str.size()-index);
			cout << temp << "起始位置:" << index << ";截取长度" << str.size() - index << endl;
			v.push_back(temp);
			break;
		}
		string temp = str.substr(index, pos-index);
		v.push_back(temp);
		cout <<temp<<"起始位置:"<<index<<";位置:" << pos << ";截取长度" << pos - index << endl;
		index = pos + 1;
	}
	for (vector<string>::iterator vs = v.begin(); vs !=v.end(); vs++){
		cout << *vs << endl;
	}


}
void test08() {
	string str = "love";
	str.insert(1, "o");	//插入
	cout << str << endl;	//loove
	str.erase(1, 1);		//删除
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
//3.1.2.9 string和c-style字符串转换
void test09()
{
	const char* str = "fucking C++";
	//const char * 转为 string
	string s(str);
	cout << str << endl;
	//string 转为 const char *
	const char* str2 = s.c_str();
	cout << str2 << endl;
	//const char * 可以隐式类型转换为  string
	doWork(str2);
	//string 不可以隐式类型转换为  const char* 
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