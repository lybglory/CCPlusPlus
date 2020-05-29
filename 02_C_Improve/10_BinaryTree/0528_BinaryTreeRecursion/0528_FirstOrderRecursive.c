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
	printf("%c ",btRoot->btName);			//1.root name
	BinaryTreeRecursion(btRoot->lChildNd);	//2.left
	BinaryTreeRecursion(btRoot->rChildNd);	//3.right


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
}
void main() {
	BinaryTreeTest();
}