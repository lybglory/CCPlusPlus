#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Crypto.h"
extern void Encryption(char *sourceFile,char *encryptFile) {

	//#英雄的Id  #-->35(ASCII)-->(0010 0011)
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
	char tmpChar;
	while ( (tmpChar = fgetc(fp_r))!=EOF ) {	//EOF just for window OS
		short tmpShort = (short)tmpChar;
		tmpShort = tmpShort << 4;
		tmpShort = tmpShort | 0x8000;		//(1000) =(8)
		tmpShort = tmpShort + rand() % 16;	//(0~15)
		//printf("%d\n", tmpShort);
		fprintf(fp_w,"%hd",tmpShort);		//write to file
	}
	fclose(fp_r);
	fclose(fp_w);
}
extern void Decryption(char* encryptFile, char* decryptFile) {
	//1000 0010 0011 0011	<<	1
	//0000 0100 0110 0110	>>	5 ( <<4  <<1 )
	//00000 0000 0100 011
	FILE *encryFP = fopen(encryptFile, "r");
	FILE *decryFP = fopen(decryptFile, "w");
	if (encryFP==NULL||decryFP==NULL) {
		perror("open error!");
		return;
	}
	short tmpShort;
	while (feof(encryFP) == 0)			//0值表示没读到结尾
	{
		fscanf(encryFP, "%hd", &tmpShort);	//Format read
		tmpShort =tmpShort << 1;		//Remove the high
		tmpShort= tmpShort >> 5;
		//tmpShort <<= 1;		//Remove the high
		//tmpShort >>= 5;
		char tempChar = (char)tmpShort;
		//printf("%c", tempChar);
		fputc(tempChar, decryFP);
	}
	fclose(encryFP);
	fclose(decryFP);
}