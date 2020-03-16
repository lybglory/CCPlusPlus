#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <strsafe.h>
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
	dst[i + j] = 0; //字符串结束符

	printf("dst = %s\n", dst);

}

void CharsIOput() {
	char str[100];

	printf("input string1 : \n");
	scanf("%s", str);//scanf(“%s”,str)默认以空格分隔
	printf("output:%s\n", str);

}

void StrLength() {
	//"hello world"加上空格总共11个字符
	char chs1[32] = "hello world";
	//strlen(chs1)字符串的实际长度，不包含\0
	printf("\"hello world\" chs1的strlen=%d\n", strlen(chs1));
	printf("\"hello world\" chs1的sizeof=%d\n", sizeof(chs1));

	char chs2[] = "hello world";
	printf("\"hello world\" chs2的strlen=%d\n", strlen(chs2));
	//sizeof(chs1)空间大小，预留一位'\0'
	printf("\"hello world\" chs2的sizeof=%d\n", sizeof(chs2));

	char chs3[] = "hello\0world";
	//strlen(chs1)字符串的实际长度，不包含\0
	printf("\"hello world\" chs3的strlen=%d\n", strlen(chs3));
	printf("\"hello world\" chs3的sizeof=%d\n", sizeof(chs3));
	
	char chs4[] = "sss//\\oxh\2020hello\0\x20world";
	/*
	"sss//\\oxh\2019hello\0world"
	sss//5个char 所以这里有5个char
	'\\oxh'两个\\输出一个反斜杠，一共有4个char
	'\2020hello' 反斜杠'\'遇到数字(ddd)，每3位表示一个8进制ASCII码，所以有7个char
	'\0'表示转义数字0，所以有1个char
	'\x20world' 反斜杠'\'遇到x数字(xhh)，每3位表示一个16进制ASCII码，所以有6个char
	总共有5+4+7+1+6+预留'\0'=24个
	*/
	printf("chs4的strlen=%d\n", strlen(chs4));
	printf("chs4的sizeof=%d\n", sizeof(chs4));
}
void main() {
	//TypeWord();
	//AppendChars();
	//CharsIOput();
	StrLength();
}