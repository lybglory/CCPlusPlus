#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void TestStrtok() {
	char buff[32] = "Today:is:202/3/7:sunny:day";
	char *array[32] = {buff,NULL};
	int i = 0;
	while ((array[i]=strtok(array[i],":"))!=NULL)
	{
		i++;
	}
	//����Ԫ�ء���֪��������while
	i = 0;
	while (array[i] != NULL)
	{
		printf("array[%d]=%s\n", i, array[i++]);
	}
	
}
void main() {
	TestStrtok();
}