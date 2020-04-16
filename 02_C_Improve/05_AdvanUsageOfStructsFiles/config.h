#pragma once
struct ConfigInfo {
	char key[20];
	char value[50];
};

int GetFileLine(const char *path);