#include <stdio.h>
void main() {
	//C语言中没有字符串这种数据类型，可以通过char的数组来替代；字符串一定是一个char的数组,
	char str[] = "zi chan";
	//"zi chan"有个字符，字符串必定以'\0'结尾。所以一共有8个
	printf("str=%s,长度=%d\n",str,sizeof(str));
	//p存储的是str数组首元素地址，str首元素地址是str[0]=='z'
	char *p = str;
	//*p存储的是p指向空间的内容,'z'变成了'y'
	*p = 'y';
	//字符数组首元素跳过一个元素str[0]+1==str[1],首元素成了'i'
	printf("#str[0]+1=%s#\n", &str[0] + 1);
	p++;
	*p = 'u';
	//最终输出:yu chan
	printf("最终结果：str=%s\n", str);

	char *str1 = "2020-02-28 1:10";
	//*str1 = "2019";//报错：写入权限冲突
	str1 = "New year";
	printf("str=%s,*str1=%c\n", str1,*str1);
	char str2[] = "zi chan 11 month";
	printf("str2=%s\n", str2);
	*(str2+2) = '-';
	printf("str2=%s\n", str2);
}
