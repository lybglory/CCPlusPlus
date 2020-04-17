#pragma once
extern struct config {
	char key[64];
	char value[64];
};
//
extern int GetFileLine(const char *path);
//
extern void Filesanalysis(const *filePath, int lines, struct config **config);
//
extern char *GetKeyValue(char *key, struct config* cfg, int lines);
//
extern void FreeStruHeap(struct config *cfg);