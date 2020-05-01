#include "Factorial.h"
_declspec(dllexport) int GetFactorial(int num) {
	if (num==1) {
		return 1;
	}
	return num * GetFactorial(num - 1);
}