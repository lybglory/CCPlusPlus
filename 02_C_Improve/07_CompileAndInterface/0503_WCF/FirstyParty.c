#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SecondParty.h"
//Init game
typedef void(*InitGame) (void **player,char *name);

//CoreCombat 1:success	0:fail
typedef int(*CoreCombat)(void *player,int gameDiff);

//show info
typedef void(*SHowInfo)(void *player);

//
typedef void(*LeaveGame)(void *player);

//function realization
void PlayGame(InitGame initgame, CoreCombat cmbt,SHowInfo show,LeaveGame leavegame) {
	void *player = NULL;
	printf("enter player name:\n");
	char name[10];
	scanf("%s",name);
	initgame(&player, name);
	int gameLevel = -1;
	while (1) {
		getchar();
		printf("Please select the difficulty of the game:\n");
		printf("1:simple\n2:medium\n3:diffcult");
		scanf("%d",&gameLevel);
		getchar();
		int cmbtRect = cmbt(player,gameLevel);
		if (cmbtRect==1) {
			printf("Congratulation!\nShow Info:");
			show(player);
		}
		else {
			printf("Game Over!");
			break;
		}
	}//while_end
	leavegame(player);
}

void main() {
	srand(time(NULL));
}