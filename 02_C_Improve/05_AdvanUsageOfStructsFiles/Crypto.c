#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Crypto.h"
#include <time.h>	//time func
extern void Encryption(char *sourceFile,char *encryptFile) {
	srand(time(NULL));
	//#Ó¢ÐÛµÄId  #-->35(ASCII)-->(0010 0011)
	//0000 0000 0010 0011 << 4
	//0000 0010 0011 0000 |		Unification goes negative
	//1000 0010 0011 0000 + rand()
	//1000 0010 0011 0011
	FILE *fp_r = fopen(sourceFile,"r");
	FILE* fp_w = fopen(encryptFile, "w");
	if (fp_r==NULL|| fp_w==NULL) {
		perror("open error!");
		return;
	}
	char temp;
	while (fgetc(fp_r)!=EOF) {		//EOF just for window OS
		temp = fgetc(fp_r);
		short tmpShort = (short)temp;
		tmpShort = tmpShort << 4;
		tmpShort = tmpShort | 0x8000;		//(1000) =(8)
		tmpShort = tmpShort + rand() % 16;	//(0~15)
		printf("%d\n", tmpShort);
		fprintf(fp_w,"%hd",tmpShort);		//write to file
	}
	fclose(fp_r);
	fclose(fp_w);
}
