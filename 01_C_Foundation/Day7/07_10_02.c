#include <stdio.h>
//num: �������ĸ�����������ִ�г���
//p��ָ�����飬ָ������Ĳ���
void main07_10(int num, char *p[]) {
	//ָ�����飬�������飬ÿ��Ԫ�ض���ָ��
	int i = 0;
	printf("num = %d\n", num);
	for (i = 0; i < num; i++) {
		//*p[i]ȡ���ַ�ָ���������ÿ��Ԫ�ص��׵�ַ��Ӧ������
		printf("p[%d]=%s; *p[%d]=%c\n ", i, p[i], i, *p[i]);
	}
}
