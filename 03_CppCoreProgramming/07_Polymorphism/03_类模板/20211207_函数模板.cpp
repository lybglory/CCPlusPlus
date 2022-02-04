#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void DataExchange(int &num1,int &num2) {
	int temp = num2;
	num2 = num1;
	num1 = temp;
}

template<typename T>
void TDataExchange(T &t1,T &t2) {
	T temp = t2;
	t2 = t1;
	t1 = temp;
}

void Test01() {
	int n1 = 31;
	int n2 = 41;
	cout << "before:n1=" << n1 << ";n2=" << n2 << endl;
	//DataExchange(n1, n2);
	TDataExchange(n1, n2);
	cout <<"after :n1=" <<n1 <<";n2="<<n2 << endl;
	char c1 = 'B';
	char c2 = 'Z';
	cout << "before:c1=" << c1 << ";c2=" << c2 << endl;

	TDataExchange<char>(c1, c2);
	cout << "after :c1=" << c1 << ";c2=" << c2 << endl;
}

template<typename T>
void TDataOrder(T Tarr[],int len) {
	for (int i = 0; i < len; i++){
		int min = i;	//��������
		for (int j = i+1; j < len; j++)
		{				//�и�С������¼�±�
			if (Tarr[min]>Tarr[j]) {
				min = j;
			}
		}
		if (i!=min) {
			TDataExchange(Tarr[i], Tarr[min]);
		}
	}
}

template <typename T>
void TPrintfData(T Tarr[],int len) {
	for (int i = 0; i < len; i++)
	{
		cout << Tarr[i] << " ";
	}
	cout << endl;
}

void ShowMesg(int n1,int n2) {
	cout << "��ͨ����" << endl;
}

template <typename T>
void ShowMesg(T t1,T t2) {	//ģ�庯��Ҳ��������
	cout << "ģ�庯��" << endl;
}
void Test03() {
	int a = 21;
	int b = 31;
	//ShowMesg();		//���ȵ�����ͨ����
	ShowMesg<>(a,b);	//ǿ�Ƶ���ģ�壬�ÿ�ģ������б�(����Ҫ�в���)
}
void Test02() {
	char chr[] = "CHINA";
	int chrlen = strlen(chr);
	TPrintfData(chr, chrlen);
	TDataOrder(chr, chrlen);
	TPrintfData(chr, chrlen);

	int intArr[] = {2021,2015,2017,2019,2014,2016,2018,2020};
	int intlen = sizeof(intArr) / sizeof(int);
	TPrintfData(intArr,intlen);
	TDataOrder(intArr, intlen);
	TPrintfData(intArr, intlen);
}

void main() {
	//Test01();
	//Test02();
	Test03();
}