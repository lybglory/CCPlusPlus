#include "EmployeeManager.h"

EmployeeManager::EmployeeManager() {
	this->m_empArr = NULL;
	this->m_empNum = 0;
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



void EmployeeManager::Exit() {
	cout << "Welcome to use next time!!" << endl;
	system("pause");
	exit(0);
}


EmployeeManager::~EmployeeManager() {}