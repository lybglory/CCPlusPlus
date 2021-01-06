#include "EmployeeManager.h"

EmployeeManager::EmployeeManager() {
	ifstream ifs;
	ifs.open(FileName, ios::in);
	//1:File does not exist!
	if (!ifs.is_open()) {
		cout << "File does not exist!" << endl;
		this->m_empNum = 0;
		this->m_empArr = NULL;
		this->fileIsExist = false;
		ifs.close();
		return;
	}
	//2:The file exists but the data is empty
	char ch;
	ifs >> ch;
	//The file exists but the data is empty
	if (ifs.eof()) {
		cout << "The file exists but the data is empty!" << endl;
		this->m_empNum = 0;
		this->m_empArr = NULL;
		this->fileIsExist = false;
		ifs.close();
		return;
	}

	//3:The file exists and has data
	int empNum = this->getEmployeeNum();
	if (empNum>0) {
		this->fileIsExist = true;
	}
	//cout << "employee numm=" << empNum << endl;
	this->m_empNum = empNum;
	this->m_empArr = new Employee *[this->m_empNum];
	this->InitEmployee();
	/*
	for (size_t i = 0; i < this->m_empNum; i++)
	{
		cout << "name:" << this->m_empArr[i]->m_name;
		cout << " id:" << this->m_empArr[i]->m_ID;
		cout << " did" << this->m_empArr[i]->m_dID<<endl;
	}
	*/
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
		this->fileIsExist = true; //update fileIsExist
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
	ofs.open(FileName, ios::out);//open file::write
	//write to file
	for (size_t i = 0; i < this->m_empNum; i++)
	{
		ofs << this->m_empArr[i]->m_ID << "\t" << this->m_empArr[i]->m_name << "\t"
			<< this->m_empArr[i]->m_dID << endl;
	}
	ofs.close();
}

int EmployeeManager::getEmployeeNum() {
	ifstream ifs;
	ifs.open(FileName,ios::in);	//open file:read
	int id;
	int dId;
	string name;
	int num=0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	ifs.close();
	return num;

}

void EmployeeManager::InitEmployee() {
	ifstream ifs;
	ifs.open(FileName, ios::in);	//open file:read
	int id;
	int dId;
	string name;
	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId) {
		Employee *employee = NULL;
		if (dId==1) {
			employee = new Clerk(id, dId, name);
		}
		else if(dId==2)
		{
			employee = new Manager(id, dId, name);
		}
		else {
			employee = new Boss(id,dId,name);
		}
		this->m_empArr[index] = employee;
		index++;
	}
	ifs.close();
}

void EmployeeManager::ShowEmployee() {
	if (this->fileIsExist) {
		for (size_t i = 0; i < m_empNum; i++)
		{
			this->m_empArr[i]->ShowInfo();
		}		
	}else{
		cout << "File does not exist!" << endl;
	}
	system("pause");
	system("cls");
}

void EmployeeManager::DeleEmployee() {
	if (this->fileIsExist) {
		int delID = 0;
		cout << "Please enter the ID you want to delete" << endl;
		cin >> delID;
		int index = EmployeeIsExist(delID);
		if (index!=-1) {	//employee exist;  m_empNum-1, last position
			for (size_t i = 0; i < this->m_empNum-1; i++)
			{
				this->m_empArr[index] = this->m_empArr[index + 1];
			}
			this->m_empNum--;
			cout << "Delete success!" << endl;
			this->SaveInfo();

		}
		else {
			cout << "Employee doesn't exist" << endl;
		}
		
	}
	else {
		cout << "File does not exist!" << endl;
		return;
	}
	system("pause");
	system("cls");
}

int EmployeeManager::EmployeeIsExist(int id) {
	int index = -1;
	for (size_t i = 0; i < this->m_empNum; i++)
	{
		if (id==this->m_empArr[i]->m_ID) {
			index = i;
		}
	}
	return index;
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