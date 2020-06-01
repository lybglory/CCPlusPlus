#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char btName;
	struct BinaryTreeNode *lChildNd;
	struct BinaryTreeNode *rChildNd;
}BinaryTreeNode;


void BinaryTreeRecursion(BinaryTreeNode *btRoot) {
	
	if (btRoot ==NULL) {
		return;
	}
	//����
	//printf("%c ",btRoot->btName);			//1.root name
	//BinaryTreeRecursion(btRoot->lChildNd);	//2.left
	//BinaryTreeRecursion(btRoot->rChildNd);	//3.right

	//inorder
	//BinaryTreeRecursion(btRoot->lChildNd);	//1.left
	//printf("%c ", btRoot->btName);			//2.root
	//BinaryTreeRecursion(btRoot->rChildNd);	//3.right

	//����
	BinaryTreeRecursion(btRoot->lChildNd);	//1.left
	BinaryTreeRecursion(btRoot->rChildNd);	//2.right
	printf("%c ", btRoot->btName);			//3.root
	
}

//get tree count
int GetTreeNode(BinaryTreeNode *btRoot,int *p_count) {
	if (btRoot==NULL) {
		return 0;
	}


	if (btRoot->rChildNd==NULL&&btRoot->lChildNd==NULL) {
		(*p_count)++;
	}
	GetTreeNode(btRoot->lChildNd, p_count);
	GetTreeNode(btRoot->rChildNd, p_count);
	return p_count;
}

void BinaryTreeTest() {
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

	BinaryTreeRecursion(&btNodeA);
	int count = 0;
	GetTreeNode(&btNodeA, &count);
	printf("\ntree node=%d\n", count);
}
void main() {
	BinaryTreeTest();
}