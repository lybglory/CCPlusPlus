#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void TestSprintf() {
	int year = 2020;
	int month = 2;
	int day = 29;
	char str[32];
	sprintf(str, "date:%d年%d月%d日", year, month, day);
	printf("str=%s",str);
}

void TestSscanf() {
	char src[64] = "Name=Chan Date=2020 02/29/1:15";
	char ch1[10]="";
	int year = 0;
	char ch2[30] = "";
	sscanf(src, "Name=%s Date=%d %s", ch1,&year,ch2);
	printf("ch1=%s; date=%d; ch2=%s\n", ch1,year,ch2);

}
void TestStrchr() {
	char buff[64] = "TodayIs2020/2/29RainingDay";
	
	char *p_rec = NULL;
	char* p_buff = buff;
	int i = 0;
	//strchr(字符串首地址,需要匹配的字符)，返回的是当前字符的地址(指针)
	while (p_rec = strchr(p_buff, 'a')) {
		i++;
		//数组名表示数组的首地址，当前地址-首地址=元素下标
		printf("当前a的地址=%x,字符数组首地址=%x\n", p_rec, p_buff);
		printf("第%d个a的下标位置=%d\n",i,p_rec-buff);
		//将字符'a'替换*
		*p_rec = '*';
		p_buff = p_rec + 1;
	}
	printf("%s", buff);
}
void main() {
	//TestSprintf();
	//TestSscanf();
	//TestSscanf();
	TestStrchr();
}

void main07_11() {
	//char dest[50] = "Tan Yuan";
	//char src[] = "-Welcome to the world";
	//strcpy(dest, src);
	//strncpy(dest,src,10);
	//strcat(dest,src);
	//strncat(dest,src,8);
	//printf("%s\n", dest);
	char str1[32] = "TanYuan";
	printf("str1=%s\n请输入一个字符串:\n", str1);
	char chrInput[32] = "";
	fgets(chrInput, sizeof(chrInput), stdin);
	/*if (strcmp(str1, chrInput) == 0) {
		printf("%s==%s\n", str1, chrInput);
	}
	else if (strcmp(str1, chrInput) > 0) {
		printf("%s>%s\n", str1, chrInput);
	}
	else {
		printf("%s<%s\n", str1, chrInput);
	}*/
	if (strncmp(str1, chrInput,3) == 0) {
		printf("str1=%s;str2=%s两个字符串前三位相等\n",str1,chrInput);
	}
}
