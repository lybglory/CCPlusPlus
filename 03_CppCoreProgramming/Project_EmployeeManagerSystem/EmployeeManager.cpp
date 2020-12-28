#include "EmployeeManager.h"

EmployeeManager::EmployeeManager() {
	
}
void EmployeeManager:: ShowMenu  () {
	cout << "******************************" << endl;
	cout << "********** Welcome! **********" << endl;
	cout << "**********  0:Quit    ********" << endl;
	cout << "**********  1:Add     ********" << endl;
	cout << "**********  2:Show    ********" << endl;
	cout << "**********  3:Delte   ********" << endl;
	cout << "**********  4:Modify  ********" << endl;
	cout << "**********  5:Find    ********" << endl;
	cout << "**********  6:Rank    ********" << endl;
	cout << "**********  7:Clear   ********" << endl;
}

EmployeeManager::~EmployeeManager() {}