//__declspec(dllexport)
__declspec(dllexport) void Hacking() {
	//pSex=12ffc13; pAge=12ffc04; pMoney=12ffbf4
	char *sex = (char *)0x12ffc13;
	*sex = 'M';
	int *age =(int *)0x12ffc04;
	*age = 30;
	double* money = (double *)0x12ffbf4;
	*money = 90;
}