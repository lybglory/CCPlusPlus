#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			}
			else
			{
				printf("Linux file\n");
			}
		}
		n++;
	}
	fclose(fp);

}

void main() {
	LinOrWin();
}