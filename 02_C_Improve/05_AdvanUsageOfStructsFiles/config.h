#pragma once
extern struct ConfigInfo {
	char key[20];
	char value[50];
};

extern int GetFileLine(const char *path);

extern void Filesanalysis(const* filePath, int lines, struct ConfigInfo** config);