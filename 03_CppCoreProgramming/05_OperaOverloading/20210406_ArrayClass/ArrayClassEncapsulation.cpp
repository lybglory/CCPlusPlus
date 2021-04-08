#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ArrayClassEncapsulation.h"
using namespace std;

MyArray::MyArray()
{
	cout << "called默认的构造函数" << endl;
	this->m_capacity = 100;
	this->m_arrSize = 0;
	this->addr = new int[this->m_capacity];
}

MyArray::MyArray(int capacity)
{
	cout << "called有参构造函数" << endl;
	this->m_capacity = capacity;
	this->m_arrSize = 0;
	this->addr = new int[this->m_capacity];
}

MyArray::MyArray(const MyArray &array)
{
	cout << "called拷贝构造函数" << endl;
	this->m_capacity = array.m_capacity;
	this->m_arrSize = array.m_arrSize;
	this->addr = new int[array.m_capacity];
	for (size_t i = 0; i < array.m_arrSize; i++)
	{
		this->addr[i] = array.addr[i];
	}
	//memcpy(this->addr, array.addr,array.m_arrSize*sizeof(int) );
}

void MyArray::TailPush(int data)
{
	this->addr[this->m_arrSize] = data;
	this->m_arrSize++;
}

void MyArray::FromPosPush(int pos,int data)
{
	this->addr[pos] = data;
}

int MyArray::GetFromPosData(int pos)
{
	return this->addr[pos];
}

int MyArray::Getcapacity()
{
	return this->m_capacity;
}

int MyArray::GetArraySize()
{
	return this->m_arrSize;
}

int &MyArray::operator[](int pos)
{
	return this->addr[pos];
}

MyArray::~MyArray()
{
	if (this->addr!=NULL) {
		cout << "虚构函数" << endl;
		delete[] this->addr;
		this->addr = NULL;
	}
}
