#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//内存操作函数需要引入string头文件
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

void main() {
	//TestMemSet();
	TestMemcpy();
}