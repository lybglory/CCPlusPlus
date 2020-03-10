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

void StruAssignt() {
	struct Person Chan = { "LZC",1,'F' };
	struct Person Tang;
	//方法1：成员变量逐个赋值
	strcpy(Tang.name,Chan.name);
	Tang.age = Chan.age;
	Tang.Gender = Chan.Gender;
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.Gender);

	//方法2:推荐(底层实现就是通过memcpy)
	Tang = Chan;
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.Gender);

	//方法3：底层实现
	memcpy(&Tang, &Chan, sizeof(struct Person));
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.Gender);
}
void SwapStructValue() {
	struct Person Chan = { "LZC",1,'F' };
	struct Person Mei = { "LXM",30,'F' };
	printf("before Chan:name=%s;age=%d;sex=%c\n", Chan.name, Chan.age, Chan.Gender);
	printf("before Mei:name=%s; age=%d; sex=%c\n", Mei.name, Mei.age, Mei.Gender);
	//方法：定义第三方相同结构体类型变量
	struct Person structTemp;
	structTemp = Chan;
	Chan = Mei;
	Mei = structTemp;
	printf("after Chan:name=%s;age=%d; sex=%c\n", Chan.name, Chan.age, Chan.Gender);
	printf("after Mei:name=%s; age=%d; sex=%c\n", Mei.name, Mei.age, Mei.Gender);
}

void main() {
	//LearnStruct();
	//InputStruct();
	//StruAssignt();
	SwapStructValue();
}