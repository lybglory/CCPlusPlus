_declspec(dllexport) void Change() {
	//arr=115f9f4; p_arr=115f9f4; &p_arr=115f9dc; 
	//&arr[9]=115fa18,arr[i]=10
	int** p_change = (int**)0x115f9dc;
	*p_change = (int*)(0x115fa18);
}