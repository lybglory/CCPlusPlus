#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "Clerk.h"
#include "Manager.h"
#include "Boss.h"
#include "Employee.h"
#define FileName "info.txt"

class EmployeeManager {
public:
	//构造函数
	EmployeeManager();
	int m_empNum;
	Employee **m_empArr;
	void AddEmployee();
	void SaveInfo();
	bool fileIsExist;
	int getEmployeeNum();

	void ShowMenu();
	void Exit();

	//虚构函数
	~EmployeeManager();

};