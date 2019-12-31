#include <stdio.h>
void testSystem() {
	char num = 0xfe + 3;
	//(f)=(15)=1111;(e)=(14)=1110;(3)=0011
	//1111	 1110
	//		+0011
	//0000	 0001=0x01
	printf("�з������%d\n", num);//1
	printf("�޷������%#x\n", num);//0x1
}

void testCharLength() {
	char num = 0x80;
	printf("�з������%d\n", num);//-128
}

void testCharAndString() {
	char cha = 'a';
	printf("cha=%d\n",cha);//�����97
	printf("str=%s\n","20191230"+4);//�����1230
	printf("%s\n", "����\0��2019��12��30��23��55��");//���������
}
void testGetchar() {
	printf("Please input a char\n");
	char ch = 0;
	ch = getchar();
	printf("ch=%c\n",ch);

	getchar();
	ch = getchar();
	printf("ch=%c\n",ch);
}

void testPutchar() {
	printf("*****\n");
	putchar('e');
	putchar(99);
}

void testPrintfOther() {
	printf("##%8d##\n", 2019);
	printf("##%6d##\n", 2019);
	printf("##%06d##\n", 2019);
	printf("##%3.3f##\n", 3.14592653);
}
void printfEveryNum() {
	int num = 1231;
	printf("1st:%d\n", num / 1000);
	printf("2sec:%d\n", num % 1000/100);
	printf("3thir:%d\n", num % 1000 % 100/10);
	printf("4four:%d\n", num % 10);
}
void main() {
	//testSystem();
	//testCharLength();
	//testCharAndString();
	//testGetchar();
	//testPrintfOther();
	printfEveryNum();
}