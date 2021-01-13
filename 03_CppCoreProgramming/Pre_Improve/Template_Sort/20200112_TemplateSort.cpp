#include <iostream>
#include <string>
using namespace std;

template<typename T>
void TSwap(T &t1,T &t2) {
	T temp = t1;
	t1 = t2;
	t2 = temp;

}

template<typename T>
void TSort(T TArray[],int len,bool isASC) {		//ASCÎªÉýÐò£¨ascending order£©
	for (size_t i = 0; i < len; i++)
	{
		int extremum = i;
		for (size_t j = i+1; j < len; j++)
		{
			if (isASC) {
				if (TArray[extremum] < TArray[j]) {
					extremum = j;
				}
			}
			else
			{
				if (TArray[extremum] > TArray[j]) {
					extremum = j;
				}
			}
		}//inlayer for_end

		if (i!=extremum) {
			TSwap(TArray[i],TArray[extremum]);
		}

	}//outlayer for_end
}

template<typename T>
void TPrintf(T TArray[],int length) {
	for (size_t i = 0; i < length; i++)
	{
		cout << TArray[i]<<" ";
	}
	cout << endl;
}

void main() {
	char chArray[] = "CHINA";
	int len = sizeof(chArray) / sizeof(char);
	cout << "before:";
	TPrintf(chArray, len);
	TSort(chArray,len,false);
	cout << "after:";
	TPrintf(chArray, len);

	int intArr[] = {2017,2021,2015,2019,2016,2018};
	int intLen = sizeof(intArr) / sizeof(int);
	cout << "before:";
	TPrintf(intArr, intLen);
	TSort(intArr, intLen, false);
	cout << "after :";
	TPrintf(intArr, intLen);

}