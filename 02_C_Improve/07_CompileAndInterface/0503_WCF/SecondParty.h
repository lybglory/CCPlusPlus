#pragma once
struct Player {
	char name[10];
	int exp;
	int level;
};

//Init game
extern void InitGameComm(void **p, char *name);

//CoreCombat 1:success	0:fail
extern int CoreCombatComm(void *p, int gameDiff);

//show info
extern void SHowInfoComm(void *p);

//end game
extern void LeaveGameComm(void *p);

//is vectory
//extern int GetExpComm(int diffcult, int winRate);