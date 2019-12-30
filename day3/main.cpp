#include <stdio.h>
void testSystem() {
	char num = 0xfe + 3;
	//(f)=(15)=1111;(e)=(14)=1110;(3)=0011
	//1111	 1110
	//		+0011
	//0000	 0001=0x01
	printf("有符号输出%d\n", num);//1
	printf("无符号输出%#x\n", num);//0x1
}

void testCharLength() {
	char num = 0x80;
	printf("有符号输出%d\n", num);//-128
}
void main() {
	testSystem();
	//testCharLength();
}