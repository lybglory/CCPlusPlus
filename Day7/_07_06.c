#include <stdio.h>
#include <string.h>//strlen函数需要引用
//案例：需求1：定义一个函数 给buf获取键盘输入，获取字符串的实际长度（遇到'\0'结束）
//需求2：定义一个函数 将buf中的大小字符变小写 小写字母变大些 其他保持不变

int GetCharArrLength(char *p_charArr,int n) {
	printf("请输入一个字符串，长度不超过%d个字符\n",n);
	//fgets()函数是安全的，不存在缓冲区溢出的问题.末尾多了'\n'
	fgets(p_charArr,n,stdin);
	int count = 0;
	while (p_charArr[count]!='\0') {
		
		//'A'的ASCII=97;		'a'=65
		if (p_charArr[count]>='a'&& p_charArr[count]<='z') {
			p_charArr[count] -= 'a' - 'A';
		}
		else if(p_charArr[count] >= 'A' && p_charArr[count] <= 'Z')
		{
			p_charArr[count] += 'a' - 'A';
		}
		count++;
	}
	return count;
}

void main() {
	//字符数组指定长度后，末尾自动补0结束
	char charArr[32] = "";
	int length = 0;
	length=GetCharArrLength(charArr,sizeof(charArr));
	int len = strlen(charArr);
	printf("字符数组长度=%d,实际长度strlen=%d\n",length,len);
	//fgets()函数是安全的，不存在缓冲区溢出的问题.末尾多了'\n'
	printf("charArr数组转换后=\"%s\"",charArr);
	//去掉回车，最后一个元素赋值0，等价'\0'结束
	charArr[len - 1] = 0;
	printf("\ncharArr数组去掉回车=\"%s\"", charArr);
}

void mainTest() {
	char str[100];
	printf("请输入str: ");
	fgets(str, sizeof(str), stdin);
	printf("str = \"%s\"\n", str);

}
void main07_06_01() {
	char c1[] = { 'c', ' ', 'p', 'r', 'o', 'g' }; //普通字符数组
	printf("c1 = %s\n", c1); //乱码，因为没有’\0’结束符

	//以‘\0’(‘\0’就是数字0)结尾的字符数组是字符串
	char c2[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0' };
	printf("c2 = %s\n", c2);

	//字符串处理以‘\0’(数字0)作为结束符，后面的'h', 'l', 'l', 'e', 'o'不会输出
	char c3[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0', 'h', 'l', 'l', 'e', 'o', '\0' };
	printf("c3 = %s\n", c3);

}