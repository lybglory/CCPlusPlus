#include <iostream>
using namespace std;
#include "EmployeeManager.h"
#include "Employee.h"
#include "Clerk.h"
#include "Manager.h"
#include "Boss.h"
void main() {
	EmployeeManager EM;
	int select = 0;
	Employee *employee = new Clerk(1,1,"Messi" );
	employee->ShowInfo();
	employee = new Manager(2, 2, "Peipu");
	employee->ShowInfo();
	employee = new Boss(3,3,"ManCity");
	employee->ShowInfo();
	
	/*
	while (true)
	{
		EM.ShowMenu();
		cout << "Please input your operation:" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			EM.Exit();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}
	*/
}