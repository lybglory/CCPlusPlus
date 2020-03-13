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
	for (int i = 0; i < num; i++){
		//printf("p_pr+%d->name=%s; age=%d; sex=%c\n", i,(p_pr+i)->name, (p_pr + i)->age, (p_pr + i)->sex);
		printf("p_pr[%d].name=%s; age=%d; sex=%c\n",i,p_pr[i].name, p_pr[i].age, p_pr[i].sex);
	}
	if (p_pr!=NULL) {
		free(p_pr);
		p_pr = NULL;
	}
}

void  StruPointerFunc(struct Person *p_stru) {
	printf("Please input msg.Format:name age sex\n");
	scanf("%s %d %c",p_stru->name,&p_stru->age, &p_stru->sex);
}

void StruArrFunc(struct Person *p_struArr,int len) {
	printf("Please input %d user msg.Format:name age sex\n",len);
	for (size_t i = 0; i < len; i++)
	{	//scanf("%s %d %c", p_struArr[i].name, &p_struArr[i].age,&p_struArr[i].sex);

		scanf("%s %d %c", (p_struArr + i)->name, &(p_struArr + i)->age, &(p_struArr + i)->sex);
		scanf("%s %d %c", (p_struArr + i)->name, &(p_struArr + i)->age, &(p_struArr + i)->sex);
	}
	//遍历数组
	for (size_t i = 0; i < len; i++)
	{
		printf("name=%s; age=%d; sex=%c\n", (p_struArr+i)->name, (p_struArr + i)->age, (p_struArr + i)->sex);
		//printf("name=%s; age=%d; sex=%c\n", p_struArr[i].name, p_struArr[i].age, p_struArr[i].sex);
	}
}
struct Loan {
	double total;
	int years;
	char *type;//指针变量作为struct member
};
void PntAsStruMemb() {
	//type保存的是"Equal payment of principal"文字常量区首元素的地址
	struct Loan house = { 48,30,"Equal payment of principal" };
	printf("total=%0.0fW years=%d type=%s\n", house.total, house.years, house.type);
	house.type = "Equality corpus and interest";
	printf("total=%0.0fW years=%d type=%s\n", house.total, house.years, house.type);
	//报错，不允许访问。因为文字常量区只读。
	house.type[0] = '*';
}

void PntHeapStruMem() {
	//结构体成员指向堆区
	struct Loan house = { 48,30,NULL };
	house.type=(char *)malloc(sizeof("等额本金"));
	memset(house.type, 0, sizeof("等额本金"));
	strcpy(house.type, "等额本金");
	printf("total=%0.0fW years=%d type=%s\n", house.total, house.years, house.type);
	//释放空间
	if (house.type != NULL) {
		free(house.type);
		house.type = NULL;
	}
}
void StruAndMemHeap() {
	struct Loan *house=NULL;
	//结构体指向堆区
	house = (struct Loadn *)malloc(sizeof(struct Loan));
	memset(house, 0, sizeof(struct Loan));
	printf("please intput loan mesg.\nFotmat:total years type:\n");

	//结构体成员向堆区申请空间，+1表示有一个字节存储'\0'
	house->type=(char *)malloc(sizeof("等额本金"));
	memset(house->type,0, sizeof("等额本金"));
	//输入double类型数据时，格式必须是%lf。输出可以是%f也可以是%lf
	scanf("%lf %d %s", &house->total, &house->years, house->type);
	printf("&house->total=%lf; &house->years=%d; house->type=%s\n", house->total, house->years, house->type);
	printf("total=%0.0lfW years=%d type=%s\n", house->total, house->years, house->type);
	//释放空间,先释放结构体成员。在释放结构体
	if (house->type != NULL) {
		free(house->type);
		house->type= NULL;
	}
	if (house != NULL) {
		free(house);
		house = NULL;
	}
}

void ConstMdStruPntMem() {
	struct Loan hse1 = {48,30,"House1"};
	struct Loan hse2 = { 35,20,"House2" };

	printf("house1=%x {%x %x %x};\n",&hse1, &hse1.total, &hse1.years, &hse1.type);
	printf("house2=%x {%x %x %x};\n",&hse2, &hse2.total, &hse2.years, &hse2.type);

	//const在*的左边:修饰的是 指向空间的内容只读。地址可读可写。
	//对于结构体来说，修饰的是结构体指向的空内容，也就是成员内容只读(成员地址其实也是只读)，结构体可读可写
	const struct Loan *repay1 = &hse1;
	printf("repay1：%0.0lfW %d %s\n", repay1->total, repay1->years, repay1->type);
	//repay1->total = 80;	//报错，成员内容只读
	repay1=&hse2;			//结构体地址可读可写
	printf("repay1：%0.0lfW %d %s\n", repay1->total, repay1->years, repay1->type);
	printf("repay1：%x %x %x\n", &repay1->total, &repay1->years, &repay1->type);

	struct Loan car = { 20,10,"car" };
	//const在*的右边:修饰的是 地址。地址只读，指向空间的可读可写。
	//对于结构体来说，修饰的是结构体的地址，也就是地址只读，指向空间的内容可读可写
	struct Loan *const repay2 = &hse2;
	//repay2 = &hse1;			//报错，结构体地址只读
	*repay2 = car;				//结构体指向的内容可读可写
	repay2->type = "等额本金";	//同理：成员内容可读可写
	printf("repay2：%0.0lfW %d %s\n", repay2->total, repay2->years, repay2->type);
	printf("repay2：%x %x %x\n", &repay2->total, &repay2->years, &repay2->type);

	struct Loan const *edu = &hse1;
	printf("edu：%x %x %x\n", &edu->total, &edu->years, &edu->type);
	edu =&car;
	printf("edu：%0.0lf %d %s\n", edu->total, edu->years, edu->type);



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
	//HeapstruArr();
	/*struct Person mei;
	memset(&mei,0,sizeof(struct Person));
	StruPointerFunc(&mei);
	printf("name=%s; age=%d; sex=%c", mei.name,mei.age,mei.sex);*/

	/*struct Person mei[3];
	memset(mei, 0, sizeof(mei));
	int n = sizeof(mei) / sizeof(mei[0]);
	printf("Array length=%d;\nsizeof(mei)=%d;\nsizeof(struct Person)=%d\n", n, sizeof(mei), sizeof(struct Person));
	StruArrFunc(mei,n);*/

	//PntAsStruMemb();
	//PntHeapStruMem();
	//StruAndMemHeap();
	ConstMdStruPntMem();
}