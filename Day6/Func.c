int GetMax(int nums[5]) {
	nums[5] = { rand() ,rand() ,rand() ,rand() ,rand() };
	//数组的长度
	int length = sizeof(nums)/sizeof(nums[0]);
	int temp = 0;
	for (int i = 0; i < length; i++)
	{

		if (nums[i]> temp) {
			temp = nums[i];
		}
	}
	return temp;
}