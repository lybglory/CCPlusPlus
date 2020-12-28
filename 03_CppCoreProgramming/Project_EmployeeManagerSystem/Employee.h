#pragma once
#include <iostream>
using namespace std;
#include <string>

class Employee {
public:
	//´¿Ðéº¯Êý
	virtual void ShowInfo() = 0;
	virtual string GetJobTile() = 0;

	int m_ID;
	int m_dID;
	string m_name;


};
