#pragma once
#include <iostream>
using namespace std;
#include "Clerk.h"
#include "Manager.h"
#include "Boss.h"
#include "Employee.h"

class EmployeeManager {
public:
	//���캯��
	EmployeeManager();
	int m_empNum;
	Employee **m_empArr;

	
	void ShowMenu();
	void Exit();

	//�鹹����
	~EmployeeManager();

};