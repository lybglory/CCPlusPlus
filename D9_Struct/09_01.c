#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person
{
	char name[10];
	int age;
	char sex;
};

struct Resume {
	struct Person personInfo;
	char education[10];
	char skill[20];
	int tel;
};
void LearnStruct() {
	struct Person Chan = {"LXM",0,'M'};
	printf("name=%s; age=%d; sex=%c\n",Chan.name,Chan.age,Chan.sex);
	strcpy(Chan.name,"Chan");
	Chan.age = 1;
	Chan.sex = 'F';
	printf("name=%s; age=%d; sex=%c\n", Chan.name, Chan.age, Chan.sex);
}
void InputStruct() {
	struct Person Chan;
	memset(&Chan,0,sizeof(Chan));
	printf("请输入结构体成员:name  age  gender\n");
	scanf("%s %d %c",Chan.name,&Chan.age,&Chan.sex);
	printf("name=%s; age=%d; sex=%c\n", Chan.name, Chan.age, Chan.sex);
}

void StruAssignt() {
	struct Person Chan = { "LZC",1,'F' };
	struct Person Tang;
	//方法1：成员变量逐个赋值
	strcpy(Tang.name,Chan.name);
	Tang.age = Chan.age;
	Tang.sex = Chan.sex;
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.sex);

	//方法2:推荐(底层实现就是通过memcpy)
	Tang = Chan;
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.sex);

	//方法3：底层实现
	memcpy(&Tang, &Chan, sizeof(struct Person));
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.sex);
}
void SwapStructValue() {
	struct Person Chan = { "LZC",1,'F' };
	struct Person Mei = { "LXM",30,'F' };
	printf("before Chan:name=%s;age=%d;sex=%c\n", Chan.name, Chan.age, Chan.sex);
	printf("before Mei:name=%s; age=%d; sex=%c\n", Mei.name, Mei.age, Mei.sex);
	//方法：定义第三方相同结构体类型变量
	struct Person structTemp;
	structTemp = Chan;
	Chan = Mei;
	Mei = structTemp;
	printf("after Chan:name=%s;age=%d; sex=%c\n", Chan.name, Chan.age, Chan.sex);
	printf("after Mei:name=%s; age=%d; sex=%c\n", Mei.name, Mei.age, Mei.sex);
}

void StructArrary() {
	struct Person StruArr[3] = { {"LYB",30,'M'},{"LXM",30,'F'},{"LZC",1,'F'} };
	int struArrLength = sizeof(StruArr) / sizeof(StruArr[0]);
	for (size_t i = 0; i < struArrLength; i++)
	{
		printf("name=%s; age=%d; gender=%c\n",StruArr[i].name,StruArr[i].age,StruArr[i].sex);
	}
}
void IOStruArr() {
	struct Person struArr[3];
	memset(struArr, 0, sizeof(struArr));
	int struArrLen = sizeof(struArr) / sizeof(struArr[0]);
	printf("Please enter a member of the structure array.\nFormart:name age gender\n");
	for (size_t i = 0; i < struArrLen; i++)
	{
		scanf("%s %d %c",struArr[i].name,&struArr[i].age,&struArr[i].sex);
	}
	for (size_t i = 0; i < struArrLen; i++)
	{
		printf("name=%s; age=%d; gender=%c\n", struArr[i].name, struArr[i].age, struArr[i].sex);
	}
}
void StruNestStru() {
	struct Resume binResume = { {"lyb",30,'F'},"BS","Full stack",10010 };
	printf("name=%s; age=%d; gender=%c;\nedu=%s; skill=%s; tel=%d\n",
		binResume.personInfo.name,
		binResume.personInfo.age,
		binResume.personInfo.sex,
		binResume.education,binResume.skill,binResume.tel);
}

void StructPointer() {
	struct Person bin = {"lyb",18,'M'};
	struct Person *p_stru = NULL;
	p_stru = &bin;
	printf("bin:name=%s; age=%d; gender=%c\n", bin.name, bin.age, bin.sex);
	printf("*p_stu:name=%s; age=%d; gender=%c\n", (*p_stru).name, (*p_stru).age, (*p_stru).sex);
	printf("p_stu->:name=%s; age=%d; gender=%c\n", p_stru->name, p_stru->age, p_stru->sex);
}

void HeapstruArr() {
	int num = 0;
	printf("Please input number:");
	struct Person *p_pr=NULL;
	scanf("%d", &num);
	//根据个数分配堆区空间
	p_pr = (struct Person *)malloc(num*sizeof(struct Person)); 
	memset(p_pr,0,num*sizeof(struct Person));
	printf("请输入%d个用户信息.Format:name age sex\n",num);
	for (size_t i = 0; i < num; i++){
		//scanf("%s %d %c", (p_pr+i)->name, &(p_pr + i)->age, &(p_pr + i)->sex);
		//scanf("%s %d %c",p_pr[i].name, &p_pr[i].age,&p_pr[i].sex);
		scanf("%s %d %c", (*(p_pr+i)).name, &(*(p_pr + i)).age, &(*(p_pr + i)).sex);
	}
	for (size_t i = 0; i < num; i++){
		//printf("p_pr+%d->name=%s; age=%d; sex=%c\n", i,(p_pr+i)->name, (p_pr + i)->age, (p_pr + i)->sex);
		printf("p_pr[%d].name=%s; age=%d; sex=%c\n",i,p_pr[i].name, p_pr[i].age, p_pr[i].sex);
	}
	if (p_pr!=NULL) {
		free(p_pr);
		p_pr = NULL;
	}
}
void main() {
	//LearnStruct();
	//InputStruct();
	//StruAssignt();
	//SwapStructValue();
	//StructArrary();
	//IOStruArr();
	//StruNestStru();
	//StructPointer();
	HeapstruArr();
}