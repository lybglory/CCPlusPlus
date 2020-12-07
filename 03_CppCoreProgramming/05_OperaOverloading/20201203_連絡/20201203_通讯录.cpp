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
	if (cntls.cntsNum<1) {
		cout << "contract is null!" << endl;
		return;
	}
	for (size_t i = 0; i < cntls.cntsNum; i++)
	{
		cout << "Name:" << cntls.cntArr[i].cntName << "\t";
		cout << "Age:" << cntls.cntArr[i].cntAge << "\t";
		cout << "Gender:" << (cntls.cntArr[i].cntGender==1 ?"男":"女")<< "\t";
		cout << "Addr:" << cntls.cntArr[i].cntAddr << "\t";
		cout << "Tel:" << cntls.cntArr[i].cntTel << endl;
	}
	system("pause");
	system("cls");
}

int ContractIsExist(ContactList *ctp,string delName) {
	if (ctp->cntsNum<1) {
		cout << "contract list is empty!" << endl;
		return-1;
	}
	for (size_t i = 0; i < ctp->cntsNum; i++)
	{
		if (ctp->cntArr[i].cntName == delName) {
			
			return i;
		}
	}
	return -1;
	
	system("pause");
	system("cls");
}

void DelContract(ContactList *ctp) {
	string  needDelName;
	cout << "Input need your del name of contract" << endl;
	cin >> needDelName;
	int rec = ContractIsExist(ctp, needDelName);
	if (rec!=-1) {
		cout << "Found contract!" << endl;
		for (size_t i = rec; i < ctp->cntsNum; i++)
		{	//后面的数据覆盖要删除的数据
			ctp->cntArr[i] = ctp->cntArr[i + 1];
		}
		ctp->cntsNum--;
		cout << "Contract has deleted!" << endl;
	}
	else {
		cout << "Contract was not found!" << endl;
	}
	system("pause");
	system("cls");
}

void FindContract(ContactList *ctp) {
	string  findName;
	cout << "Input need your found name of contract" << endl;
	cin >> findName;
	int rect = ContractIsExist(ctp, findName);
	if(rect!=-1){
		cout << "Name:" << ctp->cntArr[rect].cntName << "\t";
		cout << "Age:" << ctp->cntArr[rect].cntAge << "\t";
		cout << "Gender:" << (ctp->cntArr[rect].cntGender == 1 ? "男" : "女") << "\t";
		cout << "Addr:" << ctp->cntArr[rect].cntAddr << "\t";
		cout << "Tel:" << ctp->cntArr[rect].cntTel << endl;
	}
	
	system("pause");
	system("cls");
}

void ModifyContract(ContactList *ctp) {
	string  modifyName;
	cout << "Input need your found name of contract" << endl;
	cin >> modifyName;
	int rect = ContractIsExist(ctp, modifyName);
	int modifyType;
	if (rect != -1) {
		cout << "1:Modify name\t2:Modify Age\t3:Modify Gender\t4:Modify Addr\t5:Modify Tel" << endl;
		cin >> modifyType;
		switch (modifyType)
		{
		case 1:
		{
			cout << "Modify name:";
			string editorName;
			cin >> editorName; 
			ctp->cntArr[rect].cntName = editorName;
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "Modify age:";
			int editorAge;
			cin >> editorAge;
			ctp->cntArr[rect].cntAge = editorAge;
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Modify Gender:";
			int editorGender;
			cin >> editorGender;
			ctp->cntArr[rect].cntGender = editorGender;
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Modify Addr:";
			string editorAddr;
			cin >> editorAddr;
			ctp->cntArr[rect].cntAddr = editorAddr;
			cout << endl;
			break;
		}
		case 5:
		{
			cout << "Modify Tel:";
			int editorTel;
			cin >> editorTel;
			ctp->cntArr[rect].cntTel = editorTel;
			cout << endl;
			break;
		}

		default:
			break;
		}
		cout << "Modify successed!" << endl;
	}

	system("pause");
	system("cls");
}

void ClearContracts(ContactList *ctp) {

	if (ctp->cntsNum<1) {
		cout << "Contracts is empty!" << endl;
	}
	else {
		ctp->cntsNum = 0;
		cout << "Contracts has been Clear!" << endl;
	}
	system("pause");
	system("cls");
}

int main() {

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
		if (cin.fail()) {
			break;
		}
		switch (index)
		{
		case 1:			//new contract
			NewContract(&cntList);
			break;
		case 2:			//show contract
			ShowContract(cntList);
			break;
		case 3:			//delete contract	
			DelContract(&cntList);
			break;
		case 4:			//find contract
			FindContract(&cntList);
			break;
		case 5:			//Modify Contract
			ModifyContract(&cntList);
			break;
		case 6:			//ClearContracts
			ClearContracts(&cntList);
			break;
		case 0:
			cout << "Welcome to use next time!" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	

}