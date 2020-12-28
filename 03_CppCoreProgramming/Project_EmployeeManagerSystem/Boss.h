#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

class Boss : public Employee {
public:
	Boss(int id, int did, string name);
	virtual void ShowInfo();
	virtual string GetJobTile();

};
