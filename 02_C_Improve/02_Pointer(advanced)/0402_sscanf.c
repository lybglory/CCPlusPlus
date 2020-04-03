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
void PointerVerlay() {
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

void GetStr() {
	char *str = "email#messi@gmail.com";
	char result1[50] = { 0 };
	char result2[50] = { 0 };
	sscanf(str,"%*[a-z]#%[a-z]%*[@]%s",result1,result2);
	printf("result1=%s\nresult2=%s\n", result1,result2);
}

int FindSubStrUnderlying(char *str,char *subStr) {
	int num = 0;
	while (*str!='\0') {
		if (*str!=*subStr) {
			str++;
			num++;
			continue;
		}

		char *tempStr = str;
		char *tempSubStr = subStr;
		while (*tempSubStr!='\0')
		{	//匹配失败
			if (*tempStr!=*tempSubStr) {
				str++;
				num++;
				break;
			}

				//临时指针匹配相同情况
				tempStr++;
				tempSubStr++;
			
		}
		//子字符串的字符查找玩
		if (*tempSubStr=='\0') {
			printf("index=%d\n", num);
			return num;
		}

	}//while(*str!=0)_end

	return -1;
}

void FindSubstr2(char* str, char* subStr) {
	char *p_match = NULL;
	char *tmpStr = str;
	printf("str=%s\n",str);
	while (p_match=strstr(tmpStr,subStr)) {
		int index = p_match - str;
		printf("match! index=%d\n", index);
		tmpStr= p_match+strlen(subStr);
	}
}

void main_0402_sscanf() {
	//Test1();
	//Test2();
	//Test3();
	//GetStr();
	
	char *str = "shit! c nm! cnb cnmmlgb cnmcndycnm cnycng";
	/*
	int index= FindSubStrUnderlying(str,"cnm");
	if (index!=-1) {
		printf("find! index=%d\n",index);
	}
	else {
		printf("Not find!");
	}
	*/
	FindSubstr2(str,"cnm");

}