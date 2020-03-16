#include <stdio.h>
//num: 传参数的个数（包含可执行程序）
//p：指针数组，指向输入的参数
void main07_10(int num, char *p[]) {
	//指针数组，它是数组，每个元素都是指针
	int i = 0;
	printf("num = %d\n", num);
	for (i = 0; i < num; i++) {
		//*p[i]取出字符指针数组里的每个元素的首地址对应的内容
		printf("p[%d]=%s; *p[%d]=%c\n ", i, p[i], i, *p[i]);
	}
}
