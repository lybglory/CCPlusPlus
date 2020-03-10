#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person
{
	char name[10];
	int age;
	char Gender;
};

void LearnStruct() {
	struct Person Chan = {"LXM",0,'M'};
	printf("name=%s; age=%d; sex=%c\n",Chan.name,Chan.age,Chan.Gender);
	strcpy(Chan.name,"Chan");
	Chan.age = 1;
	Chan.Gender = 'F';
	printf("name=%s; age=%d; sex=%c\n", Chan.name, Chan.age, Chan.Gender);
}
void InputStruct() {
	struct Person Chan;
	memset(&Chan,0,sizeof(Chan));
	printf("请输入结构体成员:name  age  gender\n");
	scanf("%s %d %c",Chan.name,&Chan.age,&Chan.Gender);
	printf("name=%s; age=%d; sex=%c\n", Chan.name, Chan.age, Chan.Gender);
}

void main() {
	//LearnStruct();
	InputStruct();
}