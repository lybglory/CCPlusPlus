#pragma once
struct Linkls{
	int year;
	struct Linkls *lkNext;
};

extern struct Linkls *InitLinkls();
extern void ForeachLink(struct Linkls* lkls);
extern void InsertLink(struct Linkls* lkls, int oldVal, int newVal);