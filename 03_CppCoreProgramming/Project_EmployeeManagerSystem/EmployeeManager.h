#pragma once
#include <iostream>
using namespace std;
#include "Clerk.h"
#include "Manager.h"
#include "Boss.h"
#include "Employee.h"
#include <fstream>
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

	void ShowMenu();
	void Exit();

	//虚构函数
	~EmployeeManager();

};