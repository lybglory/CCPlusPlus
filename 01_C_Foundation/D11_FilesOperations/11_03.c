#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
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
void main() {
	//LinOrWin();
	//TestFileStat();
	TestRename();
}