#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CopyStr1(char* p_src, char* p_dest) {
	int len = strlen(p_src);
	int i = 0;
	while (i < len) {
		p_dest[i] = p_src[i];
		i++;
	}
	p_dest[len] = '\0';
}

void CopyStr2(char* p_src, char* p_dest) {
	while (*p_src != '\0') {
		*p_dest = *p_src;
		p_src++;
		p_dest++;
	}
	//
	*p_dest = '\0';
}


void CopyStr3(char* p_src, char* p_dest) {
	while (*(p_dest++)=*(p_src++)) {
		
	}
}

void test() {
	int year = 2019;	//两个变量
	int *p = NULL;
	//建立关系
	//指针指向谁，就把谁的地址赋值给指针
	p = &year;
	//通过*操作内存
	*p = 2020;
}

void CalledFunc(char *p) {
	strcpy(p,"Today is Thuesday");
}
void MainFunc() {
	char *p_str = malloc(sizeof(char)*20);
	memset(p_str,0,sizeof(char)*20);
	CalledFunc(p_str);
	printf("p_str=%s\n",p_str);
}

void CalledFunc2(char **p) {
	int len = strlen("Today is Thuesday");
	*p = (char *)malloc(sizeof(len)+1);
	memset(*p,0,sizeof(len)+1);
	strcpy(*p, "Today is Thuesday");
}
void MainFunc2() {
	char *p_str=NULL;
	CalledFunc2(&p_str);
	printf("p_str=%s\n", p_str);
	if (p_str!=NULL) {
		free(p_str);
		p_str = NULL;
	}
}
void main_0331() {
	char src[] = "2020/03/31.Today is cloudy";
	char str[100];
	//CopyStr1(src,str);
	//CopyStr2(src, str);
	CopyStr3(src, str);
	printf("str=%s\n",src);
	//MainFunc2();
}