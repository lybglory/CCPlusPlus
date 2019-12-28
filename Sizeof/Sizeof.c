#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	short a = 10;
	int b = 10;
	long c = 10l; //或者10L
	long long d = 10ll; //或者10LL

	printf("sizeof(a) = %u\n", sizeof(a));
	printf("sizeof(b) = %u\n", sizeof(b));
	printf("sizeof(c) = %u\n", sizeof(c));
	printf("sizeof(c) = %u\n", sizeof(d));

	printf("short a = %hd\n", a);
	printf("int b = %d\n", b);
	printf("long c = %ld\n", c);
	printf("long long d = %lld\n", d);

	unsigned short a2 = 20u;
	unsigned int b2 = 20u;
	unsigned long c2 = 20ul;
	unsigned long long d2 = 20ull;

	printf("unsigned short a = %hu\n", a2);
	printf("unsigned int b = %u\n", b2);
	printf("unsigned long c = %lu\n", c2);
	printf("unsigned long long d = %llu\n", d2);
	//getchar();
}
void test2() {
	int num = 99;
	scanf("%d", &num);
	printf("num=%d", num);

}
void test3() {
	int a = 123;	//定义变量a，以10进制方式赋值为123
	int b = 0567;	//定义变量b，以8进制方式赋值为0567
	int c = 0xabc;	//定义变量c，以16进制方式赋值为0xabc

	printf("a = %d\n", a);
	printf("8进制：b = %o\n", b);
	printf("10进制：b = %d\n", b);
	printf("16进制：c = %x\n", c);
	printf("16进制：c = %X\n", c);
	printf("10进制：c = %d\n", c);

	unsigned int d = 0xffffffff; //定义无符号int变量d，以16进制方式赋值
	printf("有符号方式打印：d = %d\n", d);
	printf("无符号方式打印：d = %u\n", d);
}

void test4() {
	signed int a = -1089474374; //定义有符号整型变量a
	printf("%X\n", a); //结果为 BF0FF0BA
	getchar();

	//B       F      0        F       F     0        B	      A
	//1011 1111 0000 1111 1111 0000 1011 1010

}
void main() {
	/*printf("char =%d个字节\n",sizeof(char));
	printf("short =%d个字节\n",sizeof(short));
	printf("int =%d个字节\n", sizeof(int));
	printf("float =%d个字节\n", sizeof(float));
	printf("long =%d个字节\n", sizeof(long));
	printf("double =%d个字节\n",sizeof(double));*/
	test4();
	
}
