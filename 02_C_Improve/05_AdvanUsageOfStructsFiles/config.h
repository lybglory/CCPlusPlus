#pragma once
extern struct ConfigInfo {
	char key[64];
	char value[64];
};
extern int GetFileLine(const char *path);
extern void Filesanalysis(const *filePath, int lines, struct ConfigInfo **config);
extern char *GetKeyValue(char *key, struct ConfigInfo* cfg, int lines);
extern void FreeStruHeap(struct ConfigInfo *cfg);