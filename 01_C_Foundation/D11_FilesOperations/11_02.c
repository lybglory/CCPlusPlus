#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Testrewind() {
	//"w+":¿ÉÐ´ ¿É¶Á
	FILE *fp = fopen("note.txt","w+");
	if (fp==NULL) {
		perror("fopen error!");
		return;
	}

	fputs("Date:2020/03/22 16:10\nToday is sunny day",fp);
	//fclose(fp);
	rewind(fp);
	fp= fopen("note.txt", "r");
	char chr[100] = ""; 
	while (fgets(chr, sizeof(chr), fp)) {
		printf("chr=%s", chr);
	}
	fclose(fp);
}

void Testfseek() {
	FILE *fp = fopen("note.txt","w+");
	if (fp==NULL) {
		perror("fopen error!");
		return;
	}

	fputs("Date:2020/03/22 17:00\nToday is sunny day",fp);
	//fclose(fp);
	//rewind(fp);
	fseek(fp,0, 0);
	fp= fopen("note.txt", "r");
	//fseek(fp, -18, SEEK_END);//"Today is sunny day"
	fseek(fp, 5, SEEK_SET);
	char chr[100] = ""; 
	while (fgets(chr, sizeof(chr), fp)) {
		printf("chr=%s", chr);
	}
	fclose(fp);
}
void main() {
	//Testrewind();
	Testfseek();
}