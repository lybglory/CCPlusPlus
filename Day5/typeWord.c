#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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

void main() {
	//TypeWord();
	AppendChars();
}