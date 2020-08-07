#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class Phone {	//手机类
public:
	Phone(){
		cout << "Phone的默认构造函数调用" << endl;
	}

	Phone(string pName){
		cout << "Phone的有参构造函数调用" << endl;
		m_PhoneName = pName;
	}

	~Phone(){
		cout << "Phone的析构函数调用" << endl;
	}
	string m_PhoneName;
};

class Game{		//游戏类
public:
	Game(){
		cout << "Game的默认构造函数调用" << endl;
	}

	Game(string gName){
		cout << "Game的有参构造函数调用" << endl;
		m_GameName = gName;
	}

	~Game(){
		cout << "Game的析构函数调用" << endl;
	}
	string m_GameName;
};

class Person{	//人类
public:
	Person(){
		cout << "Person的默认构造函数调用" << endl;
	}

	//初始化列表实现属性初始化
	Person(string name, string pName, string gName) :m_Name(name), m_Phone(pName), m_Game(gName){
		cout << "Person的有参构造函数调用" << endl;
	}

	void playGame(){
		cout << m_Name << " 拿着 << " << m_Phone.m_PhoneName << " >>牌手机 玩着： " << m_Game.m_GameName << endl;
	}

	~Person(){
		cout << "Person的析构函数调用" << endl;
	}

	string m_Name;	//姓名
	Phone m_Phone;	//手机
	Game m_Game;	//游戏
};

void ClassObjTest(){
	//当其他类对象 作为本类中的成员，构造的顺序是：先调用其他类对象的构造，再调用本类构造，析构顺序与构造相反
	Person p1("Tom", "苹果", "吃鸡");
	p1.playGame();
}

void main_0807_1() {
	ClassObjTest();
}

