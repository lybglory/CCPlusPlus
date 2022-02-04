#pragma  once 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class MyArray {
public:
	//�вι���
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_leng = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray &arr) {
		this->m_Capacity = arr.m_Capacity;
		this->m_leng = arr.m_leng;
		this->pAddress = new T[this->m_Capacity];
		//��������
		for (int i = 0; i <arr.m_leng; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//����=,����*this
	MyArray& operator=(const MyArray& arr){
		if (this->pAddress) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_leng = arr.m_leng;
		this->pAddress = new T[this->Capacity];
		for (int i = 0; i < arr.m_leng; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//����[] ;���ص�������
	T& operator[](int index) {
		return this->pAddress[index];
	}

	//β�巨
	void TailInsert(const T &val) {
		if (this->m_Capacity==this->m_leng) {
			return;
		}
		this->pAddress[this->m_leng] = val;
		this->m_leng++;
	}

	//��ȡ��������
	int GetArrCapacity() {
		return this->m_Capacity;
	}

	//��ȡ����(Ԫ�ظ���)
	int GetArrLeng() {
		return this->m_leng;
	}

	~MyArray() {
		if (this->pAddress) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress;	//ָ�������ʵ����ָ��
	int m_Capacity; //�����ʼ����
	int m_leng;		//����Ԫ�صĸ���(����)
};