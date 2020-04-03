#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Test() {
	char buf[3] = "abc";
	printf("buf:%s\n", buf);
}

void PointOverlay() {
	char *p = (char*)malloc(50);
	char buf[] = "2020/04/03-19:30";
	int n = strlen(buf);
	char *temp = p;

	for (int i = 0; i < n; i++){
		//*p=buf[i];
		*temp = buf[i];
		printf("*temp=%c\n", *temp);
		temp++;
		//p++;	//修改原指针指向
	}
	
	if (p != NULL){
		free(p);
		p = NULL;
	}
}

void main() {
	//Test();
	PointOverlay();
}
