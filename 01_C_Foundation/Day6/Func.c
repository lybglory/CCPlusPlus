//��������һά���飬��Ԫ�����ֵ
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