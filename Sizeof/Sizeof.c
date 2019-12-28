#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	short a = 10;
	int b = 10;
	long c = 10l; //����10L
	long long d = 10ll; //����10LL

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
	int a = 123;	//�������a����10���Ʒ�ʽ��ֵΪ123
	int b = 0567;	//�������b����8���Ʒ�ʽ��ֵΪ0567
	int c = 0xabc;	//�������c����16���Ʒ�ʽ��ֵΪ0xabc

	printf("a = %d\n", a);
	printf("8���ƣ�b = %o\n", b);
	printf("10���ƣ�b = %d\n", b);
	printf("16���ƣ�c = %x\n", c);
	printf("16���ƣ�c = %X\n", c);
	printf("10���ƣ�c = %d\n", c);

	unsigned int d = 0xffffffff; //�����޷���int����d����16���Ʒ�ʽ��ֵ
	printf("�з��ŷ�ʽ��ӡ��d = %d\n", d);
	printf("�޷��ŷ�ʽ��ӡ��d = %u\n", d);
}

void test4() {
	signed int a = -1089474374; //�����з������ͱ���a
	printf("%X\n", a); //���Ϊ BF0FF0BA
	getchar();

	//B       F      0        F       F     0        B	      A
	//1011 1111 0000 1111 1111 0000 1011 1010

}
void main() {
	/*printf("char =%d���ֽ�\n",sizeof(char));
	printf("short =%d���ֽ�\n",sizeof(short));
	printf("int =%d���ֽ�\n", sizeof(int));
	printf("float =%d���ֽ�\n", sizeof(float));
	printf("long =%d���ֽ�\n", sizeof(long));
	printf("double =%d���ֽ�\n",sizeof(double));*/
	test4();
	
}
