#include <iostream>
using namespace std;
#include "EmployeeManager.h"

void main() {
	EmployeeManager EM;
	int select = 0;
	//Employee *employee = new Clerk(1,1,"Messi" );
	//employee->ShowInfo();
	//employee = new Manager(2, 2, "Peipu");
	//employee->ShowInfo();
	//employee = new Boss(3,3,"ManCity");
	//employee->ShowInfo();
	

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
		case 1:	//Add
			EM.AddEmployee();
			break;
		case 2:	//Show
			EM.ShowEmployee();
			break;
		case 3:	//3:Delte
			EM.DeleEmployee();
			break;
		case 4:	//4:Modify
			EM.ModifyEmployee();
			break;
		case 5:	//5:Find
			EM.FindEmployee();
			break;
		case 6:	//6:Sort
			EM.SortEmployee();
			break;
		case 7:
			break;
		default:
			break;
		}
	}
	
}