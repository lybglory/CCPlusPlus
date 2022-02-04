#pragma  once 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class MyArray {
public:
	//有参构造
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_leng = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray &arr) {
		this->m_Capacity = arr.m_Capacity;
		this->m_leng = arr.m_leng;
		this->pAddress = new T[this->m_Capacity];
		//拷贝数据
		for (int i = 0; i <arr.m_leng; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//重载=,返回*this
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

	//重载[] ;返回的是索引
	T& operator[](int index) {
		return this->pAddress[index];
	}

	//尾插法
	void TailInsert(const T &val) {
		if (this->m_Capacity==this->m_leng) {
			return;
		}
		this->pAddress[this->m_leng] = val;
		this->m_leng++;
	}

	//获取数组容量
	int GetArrCapacity() {
		return this->m_Capacity;
	}

	//获取长度(元素个数)
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
	T* pAddress;	//指向堆区真实数组指针
	int m_Capacity; //数组初始容量
	int m_leng;		//数组元素的个数(长度)
};