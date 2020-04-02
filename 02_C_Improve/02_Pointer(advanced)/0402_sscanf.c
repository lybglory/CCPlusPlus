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

void GetStr() {
	char *str = "email#messi@gmail.com";
	char result1[50] = { 0 };
	char result2[50] = { 0 };
	sscanf(str,"%*[a-z]#%[a-z]%*[@]%s",result1,result2);
	printf("result1=%s\nresult2=%s\n", result1,result2);
}

int FindSubstr(char *str,char *subStr) {
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
}
void FindSubstr2(char* str, char* subStr) {
	int strLen = strlen(str);
	int subLen = strlen(subStr);
	int j = 0;

	for (size_t i = 0; i < strLen; i++)
	{

		if (str[i] == subStr[j]) {
			printf("%d Match!str[%d]=%c; %d Char\n", j, i, str[i],j);
			char *tempStr = str;
			char *tempSubStr = subStr;
			for (size_t x = 0; x < subLen; x++)
			{
				if (tempStr[i]==tempSubStr[x]) {
					
				}
			}
			
			if (j>=subLen) {
				j=0;
			}
		}
		else
		{
			printf("Not match:%d\n", i);
		}

	}
}
void main() {
	//Test1();
	//Test2();
	//Test3();
	//GetStr();
	char *str = "shit! cnm! cnb cnm cndy cn mlgb";
	/*int index=FindSubstr(str,"cm");
	if (index!=-1) {
		printf("find! index=%d\n",index);
	}
	else {
		printf("Not find!");
	}*/
	FindSubstr2(str,"cnm");
}