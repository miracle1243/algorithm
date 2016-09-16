/*
 ============================================================================
 Name        : thread_binary_tree.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : thread_binary_tree header file
 ============================================================================
 */

#ifndef THREAD_BINARY_TREE_H_
#define THREAD_BINARY_TREE_H_

#define QUEUE_MAXSIZE 50
#define FALSE 0
#define TRUE 1

typedef enum {
	SubTree,
    Thread
} NodeFlag;

typedef struct ThreadTree {
	char data;
	NodeFlag lflag;
	NodeFlag rflag;
	struct ThreadTree *left;
	struct ThreadTree *right;
} ThreadBinTree;

ThreadBinTree *ThreadBinTreeInit(ThreadBinTree *node);

int ThreadBinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n);

ThreadBinTree *ThreadBinTreeLeft(ThreadBinTree *bt);

ThreadBinTree *ThreadBinTreeRight(ThreadBinTree *bt);

int ThreadBinTreeIsEmpty(ThreadBinTree *bt);

int ThreadBinTreeDepth(ThreadBinTree *bt);

ThreadBinTree *ThreadBinTreeFind(ThreadBinTree *bt, char data);

void ThreadBinTreeClear(ThreadBinTree *bt);

void ThreadBinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p));

void ThreadBinTree_LDR(ThreadBinTree *bt,void(*oper)(ThreadBinTree *p));

void ThreadBinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p));

void ThreadBinTree_Level(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p));

void ThreadBinTreeThreading_LDR(ThreadBinTree *bt);

ThreadBinTree *ThreadBinTreeNext_LDR(ThreadBinTree *bt);

ThreadBinTree *ThreadBinTreePrevious_LDR(ThreadBinTree *bt);

void ThreadBinaryTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p));

void ThreadOper(ThreadBinTree *p);

ThreadBinTree *ThreadInitRoot();

void ThreadAddNode(ThreadBinTree *bt);

void ThreadBinTreeTest();

#endif /* THREAD_BINARY_TREE_H_ */

























