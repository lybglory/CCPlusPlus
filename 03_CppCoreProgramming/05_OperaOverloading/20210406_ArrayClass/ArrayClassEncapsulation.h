#pragma once
#include <iostream>
using namespace std;
class MyArray {

public:
	MyArray();//Ĭ�ϵĹ���
	MyArray(int capacity);//�вι���
	MyArray(const MyArray &array);//��������
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
