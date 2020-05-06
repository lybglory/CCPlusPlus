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
int CoreCombatComm(void *player, int gameDiff) {

}

//show info
void SHowInfoComm(void* player) {

}

//end game
void LeaveGameComm(void* player) {

}

//is vectory
void IsVictoryComm(void* player) {

}