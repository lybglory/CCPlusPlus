#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1 %*s��%*d	��������
void Test1(){
	//���������ո� �� \t �����
	char *date = "Date:2020/04/02 15:00.Bad year";
	char result[50] = { 0 };
	sscanf(date, "%*[a-zA-z]:%s", result);
	printf("result1=%s\n",result);

}
void Test2() {
	char result[50] = { 0 };
	char *date = "Date:2020/04/02 15:00.Bad year";
	sscanf(date, "%4s", result);
	printf("result=%s\n", result);
}

void Test3() {
	char result[50] = { 0 };
	char* date = "Date:2020/04/02 15:00.Bad year";
	sscanf(date, "%[^0-9]", result);
	printf("result=%s\n", result);
}

void main() {
	//Test1();
	//Test2();
	Test3();
}