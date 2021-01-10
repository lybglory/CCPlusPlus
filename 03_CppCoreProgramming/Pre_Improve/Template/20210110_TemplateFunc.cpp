#include <iostream>
#include <string>
using namespace std;

template<typename T>
void Swap(T &n1, T&n2) {
	T temp = n1;
	n1 = n2;
	n2 = temp;
}

void main() {
	int a = 2020;
	int b = 2021;
	 cout<< "before:	a=" << a << "; b=" << b << endl;
	 Swap<int>(a, b);
	 cout << "after:	a=" << a << "; b=" << b << endl;

	 string s1 = "Messi";
	 string s2 = "Peipu";
	 cout << "before:	s1=" << s1 << "; s2=" << s2 << endl;
	 Swap<string>(s1, s2);
	 cout << "after:	s1=" << s1 << "; s2=" << s2 << endl;
	 

}