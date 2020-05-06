#pragma once
struct Player {
	char *name;
	int exp;
	int level;
};

//Init game
extern void InitGameComm(void** player, char* name);

//CoreCombat 1:success	0:fail
extern int CoreCombatComm(void* player, int gameDiff);

//show info
extern void SHowInfoComm(void* player);

//end game
extern void LeaveGameComm(void *player);

//is vectory
extern void GetExpComm(void *player);