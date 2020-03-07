#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void TestStrtok() {
	char text[32] = "Today:is:202/3/7:sunny:day";
	char filter[2] = ":";
	char *cutArray[32] = {NULL};
	int i = 0;
	cutArray[i] = strtok(text, filter);
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
		printf("cutText=%s\n",cutText);
		cutText = strtok(NULL, filter);
		
	}
	//遍历元素。不知道长度用while
	

}

void TestAtoi() {
	char buff1[] = "20200307Today";
	int n1=atoi(buff1);
	int n2 = atoi("life9");
	printf("n1=%d; n2=%d\n",n1,n2);

	char str1[] = "-10";
	int num1 = atoi(str1);
	printf("num1 = %d\n", num1);

	char str2[] = "0.123";
	double num2 = atof(str2);
	printf("num2 = %lf\n", num2);

	//解包
	int year = 0;
	sscanf("Todayis2020", "Todayis%d", &year);
	printf("year=%d\n",year);
}
void main() {
	//TestStrtok();
	//TestStrokStand();
	TestAtoi();
}