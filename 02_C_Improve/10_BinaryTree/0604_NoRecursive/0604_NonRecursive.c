#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqStack.h"


typedef struct {
	char btName;
	struct BinaryTreeNode *lChildNd;
	struct BinaryTreeNode *rChildNd;
	int flag;							//flag bit

}BinaryTreeNode;

void NonRecursive(BinaryTreeNode *root) {

	v_Stack btVStk= SkInit();	//1¡¢init
	
	PushStack(btVStk, root);	//2¡¢push
	// As long as the number of elements in the stack is greater than 0,
	//the loop is executed
	while (GetStkCount(btVStk)>0) {
		BinaryTreeNode *topNode=GetTopStk(btVStk);//top stack
		PopStack(btVStk);
		if (topNode->flag==1) {
			//true,printf-->continue
			printf("%c\n",topNode->btName);
			continue;
		}

		//false,flag set true
		topNode->flag = 1;
		//right push
		if (topNode->rChildNd!=NULL) {
			PushStack(btVStk,topNode->rChildNd);
		}

		//left push
		if (topNode->lChildNd!=NULL) {
			PushStack(btVStk, topNode->lChildNd);
		}
		//root push
		PushStack(btVStk,topNode);
	}
	DestroyStk(btVStk);

}

void NonRecurTest() {
	BinaryTreeNode btNodeA = { 'A',NULL,NULL };
	BinaryTreeNode btNodeB = { 'B',NULL,NULL };
	BinaryTreeNode btNodeC = { 'C',NULL,NULL };
	BinaryTreeNode btNodeD = { 'D',NULL,NULL };
	BinaryTreeNode btNodeE = { 'E',NULL,NULL };
	BinaryTreeNode btNodeF = { 'F',NULL,NULL };
	BinaryTreeNode btNodeG = { 'G',NULL,NULL };
	BinaryTreeNode btNodeH = { 'H',NULL,NULL };
	btNodeA.lChildNd = &btNodeB;
	btNodeA.rChildNd = &btNodeF;

	btNodeB.rChildNd = &btNodeC;

	btNodeC.lChildNd = &btNodeD;
	btNodeC.rChildNd = &btNodeE;

	btNodeF.rChildNd = &btNodeG;

	btNodeG.lChildNd = &btNodeH;



	NonRecursive(&btNodeA);
}

void main() {
	NonRecurTest();
}