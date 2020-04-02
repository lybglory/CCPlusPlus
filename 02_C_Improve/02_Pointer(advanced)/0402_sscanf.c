#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1 %*s或%*d	跳过数据
void Test1(){
	//忽略遇到空格 或 \t 会结束
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