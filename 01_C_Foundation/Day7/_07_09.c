#include <stdio.h>
void mainmain_07_09_01() {
	//"Uinty" "C++" "GoLang" "UE4" "2020-02-28"
	//����һ������������5��Ԫ����Ԫ�ص�ַ
	char *str[5] = { "Uinty","Cplus","GoLang","UE4","2020-02-28-2:00" };
	//����ָ�����������4���ֽ�(32bitƽ̨)�������С=����Ԫ�ش�СXԪ�ظ���=4X5=20
	printf("�����С=sizeof(str)=%d\n",sizeof(str));
	int length = sizeof(str) / sizeof(str[0]);
	for (size_t i = 0; i < length; i++)
	{
		printf("%s ",str[i]);
	}
	//����ȡ"GoLang"��'L'
	printf("\n%C",*(str[2]+2));

	char str2[] = { "Unity Golang C++ UE4" };
	printf("\n%s",&str2[6]);
	char *str3[4] = { "Unity","Golang", "C++", "UE4" };
	printf("\n%p", *str3[1]);

}

void main_07_09_00() {
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
