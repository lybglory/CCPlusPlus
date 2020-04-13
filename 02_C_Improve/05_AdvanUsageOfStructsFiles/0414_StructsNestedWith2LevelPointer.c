#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char *name;
	char **family;
}Info;

void StructTwoLevelPointer(Info ***infos,int len) {		//如果没有返回值要用高级指针修饰
	int familyLen = len + 1;
	Info **ts = (Info **)malloc(sizeof(Info *)*len);
	for (int i = 0; i < len; i++)
	{	//people
		ts[i] = (Info *)malloc(sizeof(Info));
		//people name
		ts[i]->name = (char *)malloc(sizeof(char)*5);
		if (i==0) {
			strcpy(ts[i]->name, "YB");
			printf("ts[%d]=%s\n", i, ts[i]->name);
		}else if (i==1) {
			strcpy(ts[i]->name, "MZ");
			printf("ts[%d]=%s\n", i, ts[i]->name);
		}
		ts[i]->family = (char **)malloc(sizeof(char *) * familyLen);
		//people family
		for (int x = 0; x < len+1; x++)
		{
			ts[i]->family[x] = (char *)malloc(sizeof(char) * 20);
			if (x == 0) {
				sprintf(ts[i]->family[x], "%s_Mother", ts[i]->name);
				printf("ts[%d].family[%d]=%s\n", i,x, ts[i]->family[x]);
			}else if(x==1) {
				sprintf(ts[i]->family[x], "%s_Father", ts[i]->name);
				printf("ts[%d].family[%d]=%s\n", i, x, ts[i]->family[x]);
			}else if (x == 2) {
				sprintf(ts[i]->family[x], "%s_SoupBall", ts[i]->name);
				printf("ts[%d].family[%d]=%s\n", i, x, ts[i]->family[x]);
			}
		}//for_family_end
	}//for struct[]_end
	*infos = ts;	//Establishing relationship 
}
void PrintfStuctArray(Info **infos,int len) {
	if (infos == NULL) { return; }
	int familyLen = len + 1;
	for (int i = 0; i < len; i++)
	{	
		printf("%s\n",infos[i]->name);
		for (int j = 0; j < familyLen; i++)
		{
			printf("  %s\n",infos[i]->family[j]);
		}
	}
}
void CalledFunc1() {
	Info **infos = NULL;			
	int n = 2;
	StructTwoLevelPointer(&infos, n);//没有返回值，传入2级指针的地址==3级指针修饰
	PrintfStuctArray(infos,n);
}
void main() {
	CalledFunc1();
}