#pragma once
#include <iostream>
using namespace std;
#include "Clerk.h"
#include "Manager.h"
#include "Boss.h"
#include "Employee.h"

class EmployeeManager {
public:
	//构造函数
	EmployeeManager();
	int m_empNum;
	Employee **m_empArr;

	
	void ShowMenu();
	void Exit();

	//虚构函数
	~EmployeeManager();

};