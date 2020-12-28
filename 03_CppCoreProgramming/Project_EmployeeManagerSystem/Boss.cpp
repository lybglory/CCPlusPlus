#include "Boss.h"
Boss::Boss(int id, int did, string name) {
	this->m_ID = id;
	this->m_dID = did;
	this->m_name = name;
}

//override
void Boss::ShowInfo() {
	cout << "ID=" << m_ID << "\tname=" << m_name << "\tdid=" << m_dID << "\t" << this->GetJobTile()
		<< "Job Description: responsible for overall control" << endl;

}

//override
string Boss::GetJobTile() {
	return "Boss";
}