#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void main_20201125() {
	int num = 100;
	do
	{
		int g = num % 10;
		int s = num/10%10;
		int b = num/100;
		if (g * g * g + s * s * s + b * b * b == num) {//ÊÇdaffodil
			cout << num << endl;
		}
		num++;

	} while (num < 1000);
}