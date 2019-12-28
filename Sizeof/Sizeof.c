#include <stdio.h>

void main() {
	printf("char =%d个字节\n",sizeof(char));
	printf("short =%d个字节\n",sizeof(short));
	printf("int =%d个字节\n", sizeof(int));
	printf("float =%d个字节\n", sizeof(float));
	printf("long =%d个字节\n", sizeof(long));
	printf("double =%d个字节\n",sizeof(double));

	getchar();
}