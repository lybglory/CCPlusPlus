#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Person {
	char name[10];
	int age;
	char sex;
};
void TestFread() {
	struct Person Star[3] = { {"Messi",33,'M'},
							  {"Bin",30,'M'},
							  {"Mei",30,'F'} };

	FILE *wfp = fopen("Info.txt","w");
	if (wfp==NULL) {
		perror("read error!");
		return;
	}
	int count = sizeof(Star) / sizeof(Star[0]);
	fwrite(Star, sizeof(Star), count, wfp);
	fclose(wfp);
}

void main() {
	TestFread();
}

