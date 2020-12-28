#include <iostream>
#include "EmployeeManager.h"

void main() {
	EmployeeManager EM;
	int select = 0;
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
}