#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void TypeWord() {
	srand(time(NULL));
	char chars[11] = "";//定义长度为10的字符数组
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
		//开始计时
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
	printf("\n数组个数=%d\n", sizeof(chars) / sizeof(chars[0]));
	printf("\n输入的正确数：%g;\n正确率：%2.0f%%\n", score, (score/10)*100 );
	printf("所消耗的时间：%ds", timeEnd - timeStart);
}
void main() {
	TypeWord();
}