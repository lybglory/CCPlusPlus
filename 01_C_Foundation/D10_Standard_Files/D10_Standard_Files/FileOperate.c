#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//FILE *fopen(const char * filename, const char * mode);
void FilesOpen() {
	//FILE *fp = fopen("note.txt","r");
	//FILE *fp = fopen("../note.txt","r");
	FILE *fp = fopen("E://note.txt", "w");
	if (fp==NULL) {
		printf("file read error!\n");
		return;
	}
	else{
		printf("file read success!\n");
	}

}
void main() {
	FilesOpen();
}