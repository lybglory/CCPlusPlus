#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#define Max 500
//contact
struct Contact {
	string cntName;
	int cntAge;
	int cntGender;
	string cntAddr;
	string cntTel;
};

struct ContactList {
	struct Contact cntArr[Max];
	int cntsNum;
};

void ShowMenu() {
	cout << "========================" << endl;
	cout << "====1、New Contract=====" << endl;
	cout << "====2、Show Contract====" << endl;
	cout << "====3、Delete Contract==" << endl;
	cout << "====4、Find Contract====" << endl;
	cout << "====5、Modify Contract==" << endl;
	cout << "====6、Clear Contracts==" << endl;
	cout << "====0、Quit=============" << endl;
	cout << "========================" << endl;
}

void NewContract(ContactList *cntp) {
	if (cntp->cntsNum>Max) {
		cout << "contacts is full" << endl;
		return;
	}
	else {
		cout << "input name:"<<endl;
		string name;
		cin >> name;
		cntp->cntArr[cntp->cntsNum].cntName = name;

		cout << "input age:"<<endl;
		int age;
		cin >> age;
		cntp->cntArr[cntp->cntsNum].cntAge = age;

		while (true) {
			cout << "input gender(0:femal	1:male)" << endl;
			int gender;
			cin >> gender;
			if (gender==0||gender==1) {
				cntp->cntArr[cntp->cntsNum].cntGender = gender;
				break;
			}
			else {
				cout <<"input error!please check input!" << endl;
			}

		}
		cout << "input address:" << endl;
		string addr;
		cin >> addr;
		cntp->cntArr[cntp->cntsNum].cntAddr = addr;

		cout << "input telphone:" << endl;
		string telphone;
		cin >> telphone;
		cntp->cntArr[cntp->cntsNum].cntTel = telphone;
		cntp->cntsNum++;
		cout << "New contract successful!" << endl;
		system("pause");
		system("cls");
	}
}

void ShowContract(ContactList cntls) {
	if (cntls.cntsNum<0) {
		cout << "contract is null!" << endl;
		return;
	}
	for (size_t i = 0; i < cntls.cntsNum; i++)
	{
		cout << "Name:" << cntls.cntArr->cntName << "\t";
		cout << "Age:" << cntls.cntArr->cntAge << "\t";
		cout << "Gender:" << (cntls.cntArr->cntGender==1 ?"槻":"溺")<< "\t";
		cout << "Addr:" << cntls.cntArr->cntAddr << "\t";
		cout << "Tel:" << cntls.cntArr->cntTel << endl;
	}
	system("pause");
	system("cls");
}

void DeleteContract(ContactList *ctp,string delName) {
	if (ctp->cntsNum<0) {
		cout << "contract list is empty!" << endl;
		return;
	}
	for (size_t i = 0; i < ctp->cntsNum; i++)
	{
		if (ctp->cntArr[i].cntName == delName) {
			cout << "The contract was found!--delete!";
			return;
		}
	}
	cout << "The contract was not found!";
	system("pause");
	system("cls");
}

void main() {

	//2、new contractslist
	ContactList cntList;
	cntList.cntsNum = 0;
	int index=0;
	//3、select
	while (true) {
		//1、show menu
		ShowMenu();
		cout << "please input number(0~6)" << endl;

		cin >> index;

		switch (index)
		{
		case 1:			//new contract
			NewContract(&cntList);
			break;
		case 2:			//show contract
			ShowContract(cntList);
			break;
		case 3:			//delete contract
		{
			string  needDelName;
			cout << "Input need your del name of contract" << endl;
			cin >> needDelName;
			DeleteContract(&cntList,needDelName); 
		}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
	}
	

}