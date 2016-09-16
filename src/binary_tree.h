/*
 ============================================================================
 Name        : binary_tree.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : binary_tree header file
 ============================================================================
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#define QUEUE_MAXSIZE 50
#define FALSE 0
#define TRUE 1

typedef struct LinkedTree {
	char data;
	struct LinkedTree *left;
	struct LinkedTree *right;
} LinkedBinTree;

LinkedBinTree *BinTreeInit(LinkedBinTree *node);

int BinTreeAddNode(LinkedBinTree *bt, LinkedBinTree *node, int n);

LinkedBinTree *BinTreeLeft(LinkedBinTree *bt);

LinkedBinTree *BinTreeRight(LinkedBinTree *bt);

int BinTreeIsEmpty(LinkedBinTree *bt);

int BinTreeDepth(LinkedBinTree *bt);

LinkedBinTree *BinTreeFind(LinkedBinTree *bt, char data);

void BinTreeClear(LinkedBinTree *bt);

void BinTree_DLR(LinkedBinTree *bt, void (*oper)(LinkedBinTree *p));

void BinTree_LDR(LinkedBinTree *bt, void (*oper)(LinkedBinTree *p));

void BinTree_LRD(LinkedBinTree *bt, void (*oper)(LinkedBinTree *p));

void oper(LinkedBinTree *p);

void BinTree_Level(LinkedBinTree *bt, void (*oper)(LinkedBinTree *p));

LinkedBinTree *InitRoot();

void AddNode(LinkedBinTree *bt);

void BinTreeTest();

#endif /* BINARY_TREE_H_ */
















