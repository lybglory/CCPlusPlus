#include <stdio.h>
void main() {
	//C������û���ַ��������������ͣ�����ͨ��char��������������ַ���һ����һ��char������,
	char str[] = "zi chan";
	//"zi chan"�и��ַ����ַ����ض���'\0'��β������һ����8��
	printf("str=%s,����=%d\n",str,sizeof(str));
	//p�洢����str������Ԫ�ص�ַ��str��Ԫ�ص�ַ��str[0]=='z'
	char *p = str;
	//*p�洢����pָ��ռ������,'z'�����'y'
	*p = 'y';
	//�ַ�������Ԫ������һ��Ԫ��str[0]+1==str[1],��Ԫ�س���'i'
	printf("#str[0]+1=%s#\n", &str[0] + 1);
	p++;
	*p = 'u';
	//�������:yu chan
	printf("���ս����str=%s\n", str);

	char *str1 = "2020-02-28 1:10";
	//*str1 = "2019";//����д��Ȩ�޳�ͻ
	str1 = "New year";
	printf("str=%s,*str1=%c\n", str1,*str1);
	char str2[] = "zi chan 11 month";
	printf("str2=%s\n", str2);
	*(str2+2) = '-';
	printf("str2=%s\n", str2);
}
