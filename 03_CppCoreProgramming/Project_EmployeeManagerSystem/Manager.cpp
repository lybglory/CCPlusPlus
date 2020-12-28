#include "Manager.h"
Manager::Manager(int id, int did, string name) {
	this->m_ID = id;
	this->m_dID = did;
	this->m_name = name;
}

//override
void Manager::ShowInfo() {
	cout << "ID=" << m_ID << "\tname=" << m_name << "\tdid=" << m_dID << "\t" << this->GetJobTile()
		<< "Job Description£ºManager" << endl;

}

//override
string Manager::GetJobTile() {
	return "Manager";
}