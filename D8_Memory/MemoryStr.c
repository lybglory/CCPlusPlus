#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void TestStrtok() {
	char buff[32] = "Today:is:202/3/7:sunny:day";
	char filter[2] = ":";
	char *cutArray[32] = {NULL};
	int i = 0;
	cutArray[i] = strtok(buff, filter);
	while (cutArray[i]!=NULL)
	{
		int temp = i;
		printf("array[%d]=%s\n", i, cutArray[temp]);
		i++;
		cutArray[i] = strtok(NULL, filter);
	}
	
}
void TestStrokStand() {
	char text[32] = "Today:is:202/3/7:sunny:day";
	char filter[2] = ":";
	char *cutText=strtok(text, filter);
	while (cutText!=NULL)
	{
		printf("cuText=%s",cutText);
		cutText = strtok(NULL, filter);
		
	}
	//遍历元素。不知道长度用while
	

}
void main() {
	TestStrtok();
	//TestStrokStand();
}