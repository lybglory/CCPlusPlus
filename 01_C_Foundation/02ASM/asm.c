#include <stdio.h>
#include <stdlib.h>

void main() {
	int num = 5;
	printf("num=%\d,address=%x\n",num,&num);
	//%x 16进制打印地址
	_asm {
		mov eax,num //将变量num赋值给寄存器eax
		add eax, 5	//寄存器+5
		mov num,eax	//寄存器的值赋值给num
	}
	printf("num2=%\d", num);
}