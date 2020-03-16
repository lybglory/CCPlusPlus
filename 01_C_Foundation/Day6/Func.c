//传递任意一维数组，求元素最大值
int GetMax(int nums[],int n) {
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i]> temp) {
			temp = nums[i];
		}
	}
	return temp;
}