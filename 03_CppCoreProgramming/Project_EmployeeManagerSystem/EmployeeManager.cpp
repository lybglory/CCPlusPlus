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

void EmployeeManager::AddEmployee() {
	int addNum;
	cout << "Please enter the number of people you want to add" << endl;
	cin >> addNum;
	if (addNum>0) {
		int newSize = this->m_empNum + addNum;
		//old adta copy to new space
		Employee **newSpace = new Employee * [newSize];
		if (this->m_empArr!=NULL) {
			for (size_t i = 0; i < this->m_empNum; i++)
			{
				newSpace[i] = this->m_empArr[i];
			}
		}
		for (size_t i = 0; i < addNum; i++)
		{
			int id;
			int dId;
			string name;
			Employee *employ = NULL;
			cout << "Enter ID:" << endl;
			cin >> id;
			cout << "Enter name:" << endl;
			cin >> name;
			cout << "Enter Did:\t1:Clerk	\t2:Manager\t3:Boss" << endl;
			cin >> dId;
			if (dId>3&&dId<1) {
				cout << "Enter error!default did =1" << endl;
				dId = 1;
			}
			switch (dId)
			{
			case 1:
				employ = new Clerk(id,dId,name);
				break;
			case 2:
				employ = new Manager(id, dId, name);
				break;
			case 3:
				employ = new Boss(id, dId, name);
				break;
			default:
				break;
			}
			newSpace[this->m_empNum + i] = employ;
			cout << name<<" was added Successfully!" << endl;
		}//for_end
		//free old space
		delete[]this->m_empArr;
		this->m_empArr = newSpace;
		this->m_empNum = newSize;
		cout << newSize << " info was added Successfully!" << endl;
		this->SaveInfo();
	}
	else {
		cout << "enter error!" << endl;
	}

	system("pause");
	system("cls");
}

void EmployeeManager::SaveInfo() {
	ofstream ofs;
	ofs.open(FileName, ios::out);
	//write to file
	for (size_t i = 0; i < this->m_empNum; i++)
	{
		ofs << this->m_empArr[i]->m_ID << "\t" << this->m_empArr[i]->m_name << "\t"
			<< this->m_empArr[i]->m_dID << endl;
	}
	ofs.close();
}

void EmployeeManager::Exit() {
	cout << "Welcome to use next time!!" << endl;
	system("pause");
	exit(0);
}


EmployeeManager::~EmployeeManager() {
	if (this->m_empArr!=NULL) {
		delete []this->m_empArr;
		this->m_empArr = NULL;
	}
}