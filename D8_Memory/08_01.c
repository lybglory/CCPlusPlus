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

void TestMalloc() {
	int *p = NULL;
	p = (int *)malloc(sizeof(int *));
	printf("sizeof(int *)=%d,sizeof(p)=%d\n",sizeof(int *),sizeof(p));
	if (p==NULL) {
		perror("堆区申请失败");
		return;
	}
	memset(p,0,sizeof(p));
	*p = 2020;
	printf("*p=%d\n",*p);
	free(p);
	printf("释放之后：p=%d\n", *p);
}
void IOArray(int *p,int n) {
	printf("请输入%d个元素：",n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d",&p[i]);
	}

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ",p[i]);
	}
}

void TestMallocCase() {
	printf("请输入元素个数:");
	int num;
	scanf("%d",&num);

	int *p_array = NULL;
	//申请
	p_array = (int *)malloc(num*sizeof(int));
	if(p_array==NULL){
		perror("malloc申请失败");
		return;
	}
	//清空内存
	memset(p_array,0, num * sizeof(int));
	//使用
	IOArray(p_array,num);
	//释放
	free(p_array);

}
int *DoNotReturnAddr() {
	char chr[32] = "Today is sunny day";
	return &chr;
}
void DotOperaFreeSpace() {
	int *p = (int *)malloc(sizeof(int));
	memset(p,0,sizeof(int));
	*p = 2020;
	printf("p=%p; *p=%d\n",p,*p);
	free(p);
	printf("p=%p; *p=%d\n", p, *p);
}
void DotFreeSameHeapSpace() {
	char strArray[23]= "Today is 2020/3/6 0:30";
	int factLength = strlen(strArray);
	int strLength = sizeof(strArray) / sizeof(strArray[0]);
	char *p_str = (char *)malloc(strLength);
	printf("strLength=%d,fact=%d\n", strLength,factLength);
	memset(p_str,0, strLength);
	p_str = strArray;
	printf("p_str=%s\n",p_str);
	//free(p_str);
	//不要重复释放
	//free(p_str);
	if (p_str!=NULL) {
		free(p_str);
		p_str = NULL;
	}
}

void DotFreeSameHeapSpace2() {
	int num = 2020;
	int *p = (int*)malloc(sizeof(int));
	memset(p,0,sizeof(int));
	*p = num;
	printf("*p=%d\n",*p);
	free(p);
}

void DotFreeSameHeapSpace3() {
	char strArr[] = "2020-3-6";
	int strLeng = strlen(strArr);
	char *p_str = (char*)malloc(sizeof(strLeng));
	printf("length=%d,strLeng=%d\n", sizeof(char), strLeng);
	//memset(p_str, 0, strLeng);
	p_str = strArr;
	printf("p_str=%s\n", p_str);
	//free(p_str);
	//不要重复释放
	//free(p_str);
	if (p_str != NULL) {
		free(p_str);
		p_str = NULL;
	}

}

int *TestMallocSpace(int *pointer) {
	pointer = NULL;
	return pointer = (int *)malloc(sizeof(int));
}
void MallocPTP(int **pointer) {
	*pointer = (int*)malloc(sizeof(int));
}
void main() {
	//TestMemSet();
	//TestMemcpy();
	//TestMemcmp();
	//TestMalloc();
	//TestMallocCase();
	//char *p_chr = NULL;
	//p_chr=DoNotReturnAddr();
	//printf("*p_chr=%s",*p_chr);
	//DotOperaFreeSpace();
	//DotFreeSameHeapSpace();
	//DotFreeSameHeapSpace2();
	//DotFreeSameHeapSpace3();
	/*
	int *p = NULL;
	p =TestMallocSpace(p);
	*p = 2020;
	printf("*p=%d\n",*p);
	if (p!=NULL) {
		free(p);
		p = NULL;
	}
	*/

	int *p = NULL;
	MallocPTP(&p);
	*p = 2020;
	printf("*p=%d\n", *p);
	if (p != NULL) {
		free(p);
		p = NULL;
	}
	

}