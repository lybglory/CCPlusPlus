#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

class Manager : public Employee {
public:
	Manager(int id, int did, string name);
	virtual void ShowInfo();
	virtual string GetJobTile();

};
