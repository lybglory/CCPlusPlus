#include <stdio.h>
#include <stdlib.h>
//�ڴ����������Ҫ����stringͷ�ļ�
#include <string.h>
void TestMemSet() {
	char buff[32] = "TodayIs 2020/3/4";
	printf("buff=%s\n",buff);
	memset(buff, 0, sizeof(32));
	printf("#buff=%s#\n",buff);
	
}

void main() {
	TestMemSet();
}