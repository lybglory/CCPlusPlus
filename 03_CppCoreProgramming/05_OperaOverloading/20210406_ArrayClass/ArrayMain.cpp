#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "ArrayClassEncapsulation.h"

void TestArray() {
	MyArray m1;
	cout <<"Array size:"<< m1.GetArraySize() << endl;
	cout << "Array capacity:" << m1.Getcapacity() << endl;
	m1.TailPush(2021);
	m1.TailPush(2020);
	cout << "Array size:" << m1.GetArraySize() << endl;
	cout << "Array capacity:" << m1.Getcapacity() << endl;
	for (size_t i = 0; i < m1.GetArraySize(); i++)
	{
		cout << m1.GetFromPosData(i) << endl;
	}

	MyArray m2(10);
	cout << "Array size:" << m2.GetArraySize() << endl;
	cout << "Array capacity:" << m2.Getcapacity() << endl;
	m2.TailPush(1900);
	m2.TailPush(1800);
	m2.TailPush(2018);
	m2.TailPush(2019);
	m2.FromPosPush(1,2016);
	cout << "Array size:" << m2.GetArraySize() << endl;
	cout << "Array capacity:" << m2.Getcapacity() << endl;
	for (size_t i = 0; i < m2.GetArraySize(); i++)
	{
		cout << m2.GetFromPosData(i) << endl;
	}

	MyArray m3(m2);
	cout << "Array size:" << m3.GetArraySize() << endl;
	cout << "Array capacity:" << m3.Getcapacity() << endl;
	m3.TailPush(2015);
	m3.TailPush(2017);
	m3.FromPosPush(1, 2014);
	cout << "Array size:" << m3.GetArraySize() << endl;
	cout << "Array capacity:" << m3.Getcapacity() << endl;
	for (size_t i = 0; i < m3.GetArraySize(); i++)
	{
		cout << m3.GetFromPosData(i) << endl;
	}

}

void main() {
	TestArray();
}