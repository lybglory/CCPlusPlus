#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <strsafe.h>
void TypeWord() {
	srand(time(NULL));
	char chars[11] = "";//���峤��Ϊ10���ַ�����
	for (size_t i = 0; i < 10; i++)
	{	//'a'=97='a'+0' ; b'='a'+1=97+1 ; 'z'=125='a'+25
		chars[i] = 'a'+rand() % 26;
	}
	printf("%s\n",chars);

	float score = 0;
	int timeStart = 0;
	int timeEnd = 0;
	for (size_t i = 0; i < 10; i++)
	{
		char chs = _getch();
		_getch();
		//��ʼ��ʱ
		if (i==0) {
			timeStart = time(NULL);
		}
		if (chs== chars[i]) {
			score++;
			printf("%c", chs);
		}
		else {
			printf("*");
		}
	}
	timeEnd = time(NULL);
	printf("\n�������=%d\n", sizeof(chars) / sizeof(chars[0]));
	printf("\n�������ȷ����%g;\n��ȷ�ʣ�%2.0f%%\n", score, (score/10)*100 );
	printf("�����ĵ�ʱ�䣺%ds", timeEnd - timeStart);
}

void AppendChars() {
	char str1[] = "abcdef";
	char str2[] = "123456";
	char dst[100];

	int i = 0;
	while (str1[i] != 0)
	{
		dst[i] = str1[i];
		i++;
	}

	int j = 0;
	while (str2[j] != 0)
	{
		dst[i + j] = str2[j];
		j++;
	}
	dst[i + j] = 0; //�ַ���������

	printf("dst = %s\n", dst);

}

void CharsIOput() {
	char str[100];

	printf("input string1 : \n");
	scanf("%s", str);//scanf(��%s��,str)Ĭ���Կո�ָ�
	printf("output:%s\n", str);

}

void StrLength() {
	//"hello world"���Ͽո��ܹ�11���ַ�
	char chs1[32] = "hello world";
	//strlen(chs1)�ַ�����ʵ�ʳ��ȣ�������\0
	printf("\"hello world\" chs1��strlen=%d\n", strlen(chs1));
	printf("\"hello world\" chs1��sizeof=%d\n", sizeof(chs1));

	char chs2[] = "hello world";
	printf("\"hello world\" chs2��strlen=%d\n", strlen(chs2));
	//sizeof(chs1)�ռ��С��Ԥ��һλ'\0'
	printf("\"hello world\" chs2��sizeof=%d\n", sizeof(chs2));

	char chs3[] = "hello\0world";
	//strlen(chs1)�ַ�����ʵ�ʳ��ȣ�������\0
	printf("\"hello world\" chs3��strlen=%d\n", strlen(chs3));
	printf("\"hello world\" chs3��sizeof=%d\n", sizeof(chs3));
	
	char chs4[] = "sss//\\oxh\2020hello\0\x20world";
	/*
	"sss//\\oxh\2019hello\0world"
	sss//5��char ����������5��char
	'\\oxh'����\\���һ����б�ܣ�һ����4��char
	'\2020hello' ��б��'\'��������(ddd)��ÿ3λ��ʾһ��8����ASCII�룬������7��char
	'\0'��ʾת������0��������1��char
	'\x20world' ��б��'\'����x����(xhh)��ÿ3λ��ʾһ��16����ASCII�룬������6��char
	�ܹ���5+4+7+1+6+Ԥ��'\0'=24��
	*/
	printf("chs4��strlen=%d\n", strlen(chs4));
	printf("chs4��sizeof=%d\n", sizeof(chs4));
}
void main() {
	//TypeWord();
	//AppendChars();
	//CharsIOput();
	StrLength();
}