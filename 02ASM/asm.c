#include <stdio.h>
#include <stdlib.h>

void main() {
	int num = 5;
	printf("num=%\d,address=%x\n",num,&num);
	//%x 16���ƴ�ӡ��ַ
	_asm {
		mov eax,num //������num��ֵ���Ĵ���eax
		add eax, 5	//�Ĵ���+5
		mov num,eax	//�Ĵ�����ֵ��ֵ��num
	}
	printf("num2=%\d", num);
}