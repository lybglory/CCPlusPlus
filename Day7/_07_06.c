#include <stdio.h>
#include <string.h>//strlen������Ҫ����
//����������1������һ������ ��buf��ȡ�������룬��ȡ�ַ�����ʵ�ʳ��ȣ�����'\0'������
//����2������һ������ ��buf�еĴ�С�ַ���Сд Сд��ĸ���Щ �������ֲ���

int GetCharArrLength(char *p_charArr,int n) {
	printf("������һ���ַ��������Ȳ�����%d���ַ�\n",n);
	//fgets()�����ǰ�ȫ�ģ������ڻ��������������.ĩβ����'\n'
	fgets(p_charArr,n,stdin);
	int count = 0;
	while (p_charArr[count]!='\0') {
		
		//'A'��ASCII=97;		'a'=65
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
	//�ַ�����ָ�����Ⱥ�ĩβ�Զ���0����
	char charArr[32] = "";
	int length = 0;
	length=GetCharArrLength(charArr,sizeof(charArr));
	int len = strlen(charArr);
	printf("�ַ����鳤��=%d,ʵ�ʳ���strlen=%d\n",length,len);
	//fgets()�����ǰ�ȫ�ģ������ڻ��������������.ĩβ����'\n'
	printf("charArr����ת����=\"%s\"",charArr);
	//ȥ���س������һ��Ԫ�ظ�ֵ0���ȼ�'\0'����
	charArr[len - 1] = 0;
	printf("\ncharArr����ȥ���س�=\"%s\"", charArr);
}

void mainTest() {
	char str[100];
	printf("������str: ");
	fgets(str, sizeof(str), stdin);
	printf("str = \"%s\"\n", str);

}
void main07_06_01() {
	char c1[] = { 'c', ' ', 'p', 'r', 'o', 'g' }; //��ͨ�ַ�����
	printf("c1 = %s\n", c1); //���룬��Ϊû�С�\0��������

	//�ԡ�\0��(��\0����������0)��β���ַ��������ַ���
	char c2[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0' };
	printf("c2 = %s\n", c2);

	//�ַ��������ԡ�\0��(����0)��Ϊ�������������'h', 'l', 'l', 'e', 'o'�������
	char c3[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0', 'h', 'l', 'l', 'e', 'o', '\0' };
	printf("c3 = %s\n", c3);

}