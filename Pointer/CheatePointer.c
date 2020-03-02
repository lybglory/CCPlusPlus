_declspec(dllexport) void Change() {
	//arr=cff73c; p_arr=cff73c; &p_arr=cff730;
	int **p_change = (int **)0xcff730;
	*p_change = 2020;
}