#pragma once
#include <iostream>
using namespace std;
class MyArray {

public:
	MyArray();//默认的构造
	MyArray(int capacity);//有参构造
	MyArray(const MyArray &array);//拷贝构造
	void TailPush(int data);
	void FromPosPush(int pos,int data);

	int GetFromPosData(int pos);
	int Getcapacity();
	int GetArraySize();
	//override array'[]'
	int &operator[](int pos);
	
	~MyArray();
private:
	int m_capacity;
	int m_arrSize;
	int *addr;

};
