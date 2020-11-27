#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void main() {
	int arr[5] = {2018,2017,2019,2016,2020};

	int start = 0;
	int end = (sizeof(arr) / sizeof(arr[0]))-1;
	for (size_t i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		cout << arr[i]<< " ";
	}
	cout << endl;

	//exchange
	while (start<end) {	
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	//ぎゃくてん  
	for (size_t i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}