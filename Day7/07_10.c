#include <stdio.h>
void mystrcat(char *p_ch1, const char *p_ch2)
{
	int len1 = 0;
	int len2 = 0;
	while (p_ch1[len1]) {
		len1++;
	}
	while (p_ch2[len2]) {
		len2++;
	}
	printf("len1=%d,len2=%d\n",len1,len2);
	int i;
	for (i = 0; i < len2; i++)
	{
		p_ch1[len1 + i] = p_ch2[i];
	}
}

void main() {
	char str[100] = "hello zi chan";
	char str2[] = "20200228";

	mystrcat(str, str2);
	printf("str = %s\n", str);
}
