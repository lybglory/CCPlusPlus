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
void main() {
	TypeWord();
}