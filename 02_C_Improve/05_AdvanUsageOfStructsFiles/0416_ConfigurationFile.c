#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "Crypto.h"
void main() {
	int lines=GetFileLine("config.txt");
	printf("lines=%d\n",lines);
	struct config *cfgInfo = NULL;
	//
	Filesanalysis("config.txt", lines,&cfgInfo );
	printf("heroName=%s\n", GetKeyValue("heroName", cfgInfo, lines));
	printf("heroInfo=%s\n", GetKeyValue("heroInfo", cfgInfo, lines));
	FreeStruHeap(cfgInfo);
	//encryption
	Encryption("config.txt", "encryption.txt");
}
