#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void TestMemSet() {
	char buff[32] = "TodayIs 2020/3/4";
	printf("buff=%s\n",buff);
	memset(buff, 0, sizeof(32));
	printf("#buff=%s#\n",buff);
	
}
void PrintfMemcpy(char *p_chr,int n) {
	for (size_t i = 0; i < n; i++){
		printf("%c", p_chr[i]);
	}
	printf("\n");
}

void TestMemcpy() {
	//字符串操作函数遇到'\0'结束
	//内存操作函数不会遇到'\0'结束
	char srcArray[32] = "Tang Yuan\0 is smart";
	char dstArray[32];
	printf("srcArray=%s\n", srcArray);
	strcpy(dstArray, srcArray);
	printf("strcpy:");
	PrintfMemcpy(dstArray, sizeof(dstArray));
	//清空内存
	memset(dstArray, 0, sizeof(dstArray));
	memcpy(dstArray, srcArray, sizeof(srcArray));
	//格式化输出，是按照字符串来。遇到\0结束。所以要字符输出
	printf("memcpy:");
	PrintfMemcpy(dstArray,sizeof(dstArray));
}

void TestMemcmp() {
	char str1[32] = "C\0Language";
	char str2[32] = "Go\0Language";
	printf("str1=%s,str2=%s\n",str1,str2);
	if (strcmp(str1,str2)==0) {
		printf("strcmp:str1=str2\n");
	}
	else if (strcmp(str1, str2) >0) {
		printf("strcmp:str1>str2\n");
	}
	else if(strcmp(str1, str2) < 0)
	{
		printf("strcmp:str1<str2\n");
	}
	//memcmp
	if (memcmp(str1, str2,sizeof(str1)) == 0) {
		printf("memcmp:str1=str2\n");
	}
	else if (memcmp(str1, str2, sizeof(str1)) > 0) {
		printf("memcmp:str1>str2\n");
	}
	else if (memcmp(str1, str2, sizeof(str1)) < 0)
	{
		printf("memcmp:str1<str2\n");
	}
	int n1[] = { 2020,03,05};
	int n2[] = {2019,03,27};
	if (memcmp(n1, n2, sizeof(n1)) == 0) {
		printf("memcmp:n1=n2\n");
	}
	else if (memcmp(n1, n2, sizeof(n1)) > 0) {
		printf("memcmp:n1>n2\n");
	}
	else if (memcmp(n1, n2, sizeof(n1)) < 0)
	{
		printf("memcmp:n1<n2\n");
	}
}
void main() {
	//TestMemSet();
	//TestMemcpy();
	TestMemcmp();
}