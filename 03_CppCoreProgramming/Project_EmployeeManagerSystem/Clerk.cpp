#include "Clerk.h"
Clerk::Clerk(int id, int did, string name) {
	this->m_ID = id;
	this->m_dID = did;
	this->m_name = name;
}

//override
void Clerk::ShowInfo() {
	cout << "ID=" << m_ID << "\tname="<<m_name<<"\tdid="<< m_dID <<"\t"<<this->GetJobTile()
		<<"Job Description£ºÉçÐó"<<endl;

}

//override
string Clerk::GetJobTile() {
	return "Clerk";
}