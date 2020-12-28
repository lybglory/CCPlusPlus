#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

class Clerk :public Employee
{
public:
	Clerk(int id, int did, string name);
	virtual void ShowInfo();
	virtual string GetJobTile();
};

