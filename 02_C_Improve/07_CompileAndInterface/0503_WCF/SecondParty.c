#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SecondParty.h"
//Init game
void InitGameComm(void **player, char *name) {

	struct Player *pl=(struct Player *)malloc(sizeof(struct Player));
	if (pl==NULL) {
		perror("player malloc error");
		return;
	}
	*player = pl;
	strcpy(pl->name, name);
	pl->exp = 0;
	pl->level = 0;
}

//CoreCombat 1:success	0:fail
int CoreCombatComm(void *p, int gameDiff) {
	struct Player *pl = p;
	int tempExp = 0;
	switch (gameDiff)
	{
	case 1:
		tempExp =GetExpComm(gameDiff,80);
		break;
	case 2:
		tempExp = GetExpComm(gameDiff, 50);
		break;
	case 3:
		tempExp = GetExpComm(gameDiff, 20);
		break;
	}

	pl->exp += tempExp;
	pl->level = (pl->exp) / 10;

	if (tempExp == 0) {
		//printf("Game Over!");
		return 0;
	}else {
		return 1;
	}
}

//show info
void SHowInfoComm(void* player) {

}

//end game
void LeaveGameComm(void* player) {

}

//is vectory
int GetExpComm(int diffcult,int winRate) {
	int rdm = rand() % 100+1; //1~100
	//easy:1~90%  medium:1~50%  diffcult:1~30%
	if (rdm<=winRate) {
		//victory! return exp;
		return diffcult * 10;
	}else {
		//fail!
		return 0;
	}
}