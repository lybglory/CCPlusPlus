#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern void SetMallocElem(int **p,int n) {
	printf("Set:p=%x\n", p);
	printf("Please set the value of each element(Total:%d):\n",n);
	*p = NULL;
	*p = (int*)malloc(n*sizeof(int));
	memset(*p,0, n * sizeof(int));
	for (size_t i = 0; i < n; i++)
	{
		printf("No.%d: ",i+1);
		scanf("%d", *p+i);
	}
	for (size_t i = 0; i < n; i++)
	{	//取二级指针指向空间的内容
		printf("%d ", *(*p+i));
	}
	printf("\n");
}
extern void MallocCompare(int *p,int n) {
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = 0; j < n-1-i; j++)
		{
			if (p[j]>p[j+1]) {
				int temp = 0;
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

extern void PrintfMallocElem(int *p,int n) {
	printf("Printf:p=%p\n",p);
	for (int i = 0; i < n; i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}

