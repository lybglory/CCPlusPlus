#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include<Windows.h>
void LinOrWin() {
	FILE *fp = fopen("prose.txt", "rb");
	if (fp==NULL) {
		perror("open error!");
		return;
	}
	char buff[1024] = {0};
	fgets(buff, sizeof(buff), fp);
	int n = 0;
	while (buff[n]) {
		if (buff[n]=='\n') {
			if (buff[n-1]=='\r') {
				printf("windows file\n");
			}else{
				printf("Linux file\n");
			}
		}
		n++;
	}
	fclose(fp);
}

void TestFileStat() {
	struct stat fileSt = {0};
	//stat�ڶ����������ǽṹ��ָ�룬���Դ���struct��ַ�Ϳ���
	stat("prose.txt", &fileSt);
	//�õ����ļ����һ�η���ʱ��
	time_t fTime = fileSt.st_atime;
	struct tm *timeInfo;
	timeInfo = localtime(&fTime);
	printf("last access time:%s\n", asctime(timeInfo));
}

void TestRename() {
	//rename("rename.txt","newName.txt");
	remove("newName.txt");
}

void TestFilebuffer() {
	//�ر�ˢ��
	//printf("Date:2020/3/23 23:30");
	//return;

	//��ˢ��
	//printf("Date:2020/3/23 23:30\n");
	//while (1);
	//return;

	//ǿ��ˢ��
	/*printf("Date:2020/3/23 23:30\n");
	fflush(stdout);
	while (1);
	return;*/

	/*char chr;
	chr = getchar();
	printf("chr=%c\n",chr);
	system("PAUSE");
	while ((chr=getchar())!='\n') {
		printf("%c",chr);
	}
	system("PAUSE");*/
	int n;
	char c;
	scanf("%d",&n);
	//fflush(stdin);
	c = getchar();
	printf("n=%d; c=#%c#\n",n,c);
	system("PAUSE");
	
}
void main() {
	//LinOrWin();
	//TestFileStat();
	//TestRename();
	TestFilebuffer();
}