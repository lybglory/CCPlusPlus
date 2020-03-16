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
	printf("������ṹ���Ա:name  age  gender\n");
	scanf("%s %d %c",Chan.name,&Chan.age,&Chan.sex);
	printf("name=%s; age=%d; sex=%c\n", Chan.name, Chan.age, Chan.sex);
}

void StruAssignt() {
	struct Person Chan = { "LZC",1,'F' };
	struct Person Tang;
	//����1����Ա���������ֵ
	strcpy(Tang.name,Chan.name);
	Tang.age = Chan.age;
	Tang.sex = Chan.sex;
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.sex);

	//����2:�Ƽ�(�ײ�ʵ�־���ͨ��memcpy)
	Tang = Chan;
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.sex);

	//����3���ײ�ʵ��
	memcpy(&Tang, &Chan, sizeof(struct Person));
	printf("Tang:name=%s; age=%d; sex=%c\n", Tang.name, Tang.age, Tang.sex);
}
void SwapStructValue() {
	struct Person Chan = { "LZC",1,'F' };
	struct Person Mei = { "LXM",30,'F' };
	printf("before Chan:name=%s;age=%d;sex=%c\n", Chan.name, Chan.age, Chan.sex);
	printf("before Mei:name=%s; age=%d; sex=%c\n", Mei.name, Mei.age, Mei.sex);
	//�����������������ͬ�ṹ�����ͱ���
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
	//���ݸ�����������ռ�
	p_pr = (struct Person *)malloc(num*sizeof(struct Person)); 
	memset(p_pr,0,num*sizeof(struct Person));
	printf("������%d���û���Ϣ.Format:name age sex\n",num);
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
	//��������
	for (size_t i = 0; i < len; i++)
	{
		printf("name=%s; age=%d; sex=%c\n", (p_struArr+i)->name, (p_struArr + i)->age, (p_struArr + i)->sex);
		//printf("name=%s; age=%d; sex=%c\n", p_struArr[i].name, p_struArr[i].age, p_struArr[i].sex);
	}
}
struct Loan {
	double total;
	int years;
	char *type;//ָ�������Ϊstruct member
};
void PntAsStruMemb() {
	//type�������"Equal payment of principal"���ֳ�������Ԫ�صĵ�ַ
	struct Loan house = { 48,30,"Equal payment of principal" };
	printf("total=%0.0fW years=%d type=%s\n", house.total, house.years, house.type);
	house.type = "Equality corpus and interest";
	printf("total=%0.0fW years=%d type=%s\n", house.total, house.years, house.type);
	//������������ʡ���Ϊ���ֳ�����ֻ����
	house.type[0] = '*';
}

void PntHeapStruMem() {
	//�ṹ���Աָ�����
	struct Loan house = { 48,30,NULL };
	house.type=(char *)malloc(sizeof("�ȶ��"));
	memset(house.type, 0, sizeof("�ȶ��"));
	strcpy(house.type, "�ȶ��");
	printf("total=%0.0fW years=%d type=%s\n", house.total, house.years, house.type);
	//�ͷſռ�
	if (house.type != NULL) {
		free(house.type);
		house.type = NULL;
	}
}
void StruAndMemHeap() {
	struct Loan *house=NULL;
	//�ṹ��ָ�����
	house = (struct Loadn *)malloc(sizeof(struct Loan));
	memset(house, 0, sizeof(struct Loan));
	printf("please intput loan mesg.\nFotmat:total years type:\n");

	//�ṹ���Ա���������ռ䣬+1��ʾ��һ���ֽڴ洢'\0'
	house->type=(char *)malloc(sizeof("�ȶ��"));
	memset(house->type,0, sizeof("�ȶ��"));
	//����double��������ʱ����ʽ������%lf�����������%fҲ������%lf
	scanf("%lf %d %s", &house->total, &house->years, house->type);
	printf("&house->total=%lf; &house->years=%d; house->type=%s\n", house->total, house->years, house->type);
	printf("total=%0.0lfW years=%d type=%s\n", house->total, house->years, house->type);
	//�ͷſռ�,���ͷŽṹ���Ա�����ͷŽṹ��
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

	//const��*�����:���ε��� ָ��ռ������ֻ������ַ�ɶ���д��
	//���ڽṹ����˵�����ε��ǽṹ��ָ��Ŀ����ݣ�Ҳ���ǳ�Ա����ֻ��(��Ա��ַ��ʵҲ��ֻ��)���ṹ��ɶ���д
	const struct Loan *repay1 = &hse1;
	printf("repay1��%0.0lfW %d %s\n", repay1->total, repay1->years, repay1->type);
	//repay1->total = 80;	//������Ա����ֻ��
	repay1=&hse2;			//�ṹ���ַ�ɶ���д
	printf("repay1��%0.0lfW %d %s\n", repay1->total, repay1->years, repay1->type);
	printf("repay1��%x %x %x\n", &repay1->total, &repay1->years, &repay1->type);

	struct Loan car = { 20,10,"car" };
	//const��*���ұ�:���ε��� ��ַ����ַֻ����ָ��ռ�Ŀɶ���д��
	//���ڽṹ����˵�����ε��ǽṹ��ĵ�ַ��Ҳ���ǵ�ַֻ����ָ��ռ�����ݿɶ���д
	struct Loan *const repay2 = &hse2;
	//repay2 = &hse1;			//�����ṹ���ַֻ��
	*repay2 = car;				//�ṹ��ָ������ݿɶ���д
	repay2->type = "�ȶ��";	//ͬ����Ա���ݿɶ���д
	printf("repay2��%0.0lfW %d %s\n", repay2->total, repay2->years, repay2->type);
	printf("repay2��%x %x %x\n", &repay2->total, &repay2->years, &repay2->type);

}

void TestConstPoint() {
	const int *p_cnst = 2020;
	int const *p_cnst2 = 5;
	int num = 314;
	int year= 2019;
	//*p_cnst = 314;		//���󣬲���ͨ��ָ��ı������ֵ
	p_cnst = &num;			//��ȷ������ͨ���������������ı������ֵ
	p_cnst = &year;
	printf("*p_cnst=%d\n", *p_cnst);
}

void PointerConst() {
	int year = 2020;
	int *const p_cnst=&year;//Ҫ���ϳ�ʼ��(ֻ�ܳ�ʼ����ַ)��֮���޷���ֵ
	int date = 314;
	//p_cnst = &date;		//����ָ�볣��ָ����ָ�뱾����һ������������ָ��������ַ
	*p_cnst = date;			//��ȷ����ַ��ָ������ݿ��Ըı�
	int days = 365;
	const int *const p_day = &days;//����ֻ�ܳ�ʼ����ַ
	printf("*p_cnst=%d *p_day=%d\n",*p_cnst,*p_day);
}
union Category
{
	int class;		//�༶
	char *title;	//ְ��
};
union Info {
	double deposit;
	int family;
	char *estate;
};
void UnionStru() {
	char *str = "house";
	union Info bin;
	bin.deposit = 90.19;
	bin.family = 7;
	//ָ���Աд������Է���������Ա����ĳ�Ա���ǵ�����
	bin.estate = str;//
	printf("%0.2lf %x %s eastate=%x",bin.deposit,bin.family,bin.estate,bin.estate);
}

void UnionTest2() {
	//union Category lxm = {1,"national"};		//���󣺲��ܳ�ʼ��ȫ����Ա������ռ��ͬһ�δ洢��Ԫ
	union Category lzc = { 0 };//��ȷ���Ե�һ����Ա��ʼ��
    union Category lxm = {lxm.title="national"};//�����ָ����һ����Ա��ʼ��
}

union Data {
	int n;
	short sh;
	char chr;
};
void UnionTest3() {
	union Data dt;
	//ÿ1λʮ������ ��Ӧ 4λ������
	//ÿ1λ�˽���   ��Ӧ 3λ������
	//ÿ3λ������   ��Ӧ 1λ�˽���
	dt.n = 0x87654321;
	printf("dt.n=%d; dt.sh=%hd; dt.chr=%c\n", dt.n, dt.sh, dt.chr);
	printf("dt.n=%x; dt.sh=%x; dt.chr=%x\n",dt.n,dt.sh,dt.chr);
}
struct FamilyMsg {
	int age;
	char name[10];
	char sex;
	union Proprietary {
		char class[15];
		char job[15];
	};
}persons[2];

void UnionExert() {
	int n = sizeof(persons) / sizeof(persons[0]);
	for (int i = 0; i < n; i++)
	{
		persons[i].age = 18;
		persons[i].sex = 'F';
	}

	strcpy(persons[0].name, "mei");
	strcpy(persons[1].name, "lian");

	strcpy(persons[0].job, "teacher");
	strcpy(persons[1].class, "College Senior");
	for (size_t i = 0; i < n; i++)
	{
		printf("age=%d; name=%s; sex=%c; class=%s; job=%s\n", persons[i].age, persons[i].name, persons[i].sex, persons[i].class,persons[i].job);
	}
}
void UnionFunc() {
	struct FamilyMsg bin;
	bin.age = 30;
	strcpy(bin.name,"Messi");
	bin.sex = 'M';
	strcpy(bin.job, "King");
	printf("bin:age=%d; name=%s; sex=%c; job=%s\n",bin.age,bin.name,bin.sex,bin.job);

	struct FamilyMsg zc;
	zc.age = 30;
	strcpy(zc.name, "Chan");
	zc.sex = 'F';
	strcpy(zc.class, "Childhood");
	printf("Chan:age=%d; name=%s; sex=%c; class=%s\n", zc.age, zc.name, zc.sex, zc.class);
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
	//ConstMdStruPntMem();
	//TestConstPoint();
	//PointerConst();
	//UnionStru();
	//UnionTest3();
	//UnionFunc();
	UnionExert();
}