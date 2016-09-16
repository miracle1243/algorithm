/*
 ============================================================================
 Name        : thread_binary_tree.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : thread_binary_tree c source file
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "thread_binary_tree.h"

ThreadBinTree *ThreadBinTreeInit(ThreadBinTree *node) {
	if(node != NULL)
		return node;
	else
		return NULL;
}

int ThreadBinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n) {
	if (bt == NULL) {
		printf("父结点不存在，请先设置父结点!\n");
		return FALSE;
	}

	switch(n) {
		case 1:
			if (bt->left) {
				printf("左子树结点不为空!\n");
				return FALSE;
			} else {
				bt->left = node;
			}
			break;
		case 2:
			if (bt->right) {
				printf("右子树结点不为空!\n");
				return FALSE;
			} else {
				bt->right = node;
			}
			break;
		 default:
			printf("参数错误!\n");
			return FALSE;
	}

	return TRUE;
}

ThreadBinTree *ThreadBinTreeLeft(ThreadBinTree *bt) {
	if(bt)
		return bt->left;
	else
		return NULL;
}

ThreadBinTree *ThreadBinTreeRight(ThreadBinTree *bt) {
	if(bt)
		return bt->right;
	else
		return NULL;
}

int ThreadBinTreeIsEmpty(ThreadBinTree *bt) {
	if(bt)
		return FALSE;
	else
		return TRUE;
}

int ThreadBinTreeDepth(ThreadBinTree *bt) {
	int dep1, dep2;
	if (bt == NULL) {
		return FALSE;
	} else {
		dep1 = ThreadBinTreeDepth(bt->left);
		dep2 = ThreadBinTreeDepth(bt->right);

		if (dep1 > dep2) {
			return dep1 + 1;
		} else {
			return dep2 + 1;
		}
	}
}

ThreadBinTree *ThreadBinTreeFind(ThreadBinTree *bt, char data) {
	ThreadBinTree *p;
	if (bt == NULL) {
		return NULL;
	} else {
		if (bt->data == data) {
			return bt;
		} else if (p=ThreadBinTreeFind(bt->left, data)) {
			return p;
		} else if (p=ThreadBinTreeFind(bt->right, data)) {
			return p;
		} else {
			 return NULL;
		}
	}
}

void ThreadBinTreeClear(ThreadBinTree *bt) {
	if(bt) {
		ThreadBinTreeClear(bt->left);
		ThreadBinTreeClear(bt->right);
		free(bt);
		bt=NULL;
	}
	return;
}

void ThreadBinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) {
	if (bt) {
		ThreadOper(bt);
		ThreadBinTree_DLR(bt->left, oper);
		ThreadBinTree_DLR(bt->right, oper);
	}
	return;
}

void ThreadBinTree_LDR(ThreadBinTree *bt,void(*oper)(ThreadBinTree *p)) {
	if(bt) {
		ThreadBinTree_LDR(bt->left,oper);
		ThreadOper(bt);
		ThreadBinTree_LDR(bt->right,oper);
	}
	return;
}

void ThreadBinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) {
	if(bt) {
		ThreadBinTree_LRD(bt->left,oper);
		ThreadBinTree_LRD(bt->right,oper);
		ThreadOper(bt);
	}
	return;
}

void ThreadBinTree_Level(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) {
	ThreadBinTree *p;
	ThreadBinTree *q[QUEUE_MAXSIZE];
	int head = 0, tail = 0;
	if (bt) {
		tail = (tail+1)%QUEUE_MAXSIZE;
		q[tail] = bt;
	}

	while (head != tail) {
		head = (head+1)%QUEUE_MAXSIZE;
		p = q[head];
		oper(p);
		if (p->left != NULL) {
			tail = (tail+1)%QUEUE_MAXSIZE;
			q[tail] = p->left;
		}

		if (p->right != NULL) {
			tail = (tail+1)%QUEUE_MAXSIZE;
			q[tail] = p->right;
		}
	}

	return;
}

void ThreadBinTreeThreading_LDR(ThreadBinTree *bt) {
	ThreadBinTree *previous=NULL;
	if (bt) {
		ThreadBinTreeThreading_LDR(bt->left);
		bt->lflag = (bt->left) ? SubTree : Thread;
		bt->rflag = (bt->right) ? SubTree : Thread;
	}
	if (previous) {
		if (previous->rflag == Thread) {
			previous->right = bt;
		}
		if (previous->lflag == Thread) {
			bt->left = previous;
		}
		previous = bt;
		ThreadBinTreeThreading_LDR(bt->right);
	}
}

ThreadBinTree *ThreadBinTreeNext_LDR(ThreadBinTree *bt) {
	ThreadBinTree *nextnode;
	if(!bt)
		return NULL;

	if(bt->rflag==Thread)
		return bt->right;
	else{
		nextnode=bt->right;
		while(nextnode->lflag==SubTree)
			nextnode=nextnode->left;

		return nextnode;
	}
}

ThreadBinTree *ThreadBinTreePrevious_LDR(ThreadBinTree *bt) {
	ThreadBinTree *prenode;
	if(!bt)
		return NULL;

	if(bt->lflag==Thread)
		return bt->left;
	else{
		prenode=bt->left;
		while(prenode->rflag==SubTree)
			prenode=prenode->left;

		return prenode;
	}
}

void ThreadBinaryTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) {
	if (bt) {
		while (bt->lflag == SubTree) {
			bt = bt->left;
		}
		do {
			oper(bt);
			bt = ThreadBinTreeNext_LDR(bt);
		} while (bt);
	}
}

void ThreadOper(ThreadBinTree *p) {
	printf("%c ",p->data);
	return;
}

ThreadBinTree *ThreadInitRoot() {
	ThreadBinTree *node;
	if(node=(ThreadBinTree *)malloc(sizeof(ThreadBinTree))) {
		printf("\n输入根结点数据:");
		fflush(stdin);
		scanf("%c",&node->data);
		node->left=NULL;
		node->right=NULL;
		return ThreadBinTreeInit(node);
	}
	return NULL;
}

void ThreadAddNode(ThreadBinTree *bt) {
	ThreadBinTree *node,*parent;
	char data;
	int select;
	if(node=(ThreadBinTree *)malloc(sizeof(ThreadBinTree))) {
		printf("\n输入二叉树结点数据:");
		fflush(stdin);
		scanf("%c",&node->data);
		node->left=NULL;
		node->right=NULL;

		printf("输入父结点数据:");
		fflush(stdin);
		scanf("%c",&data);
		parent=ThreadBinTreeFind(bt,data);
		if(!parent) {
			printf("未找到父结点!\n");
			free(node);
			return;
		}

		printf("1.添加到左子树\n2.添加到右子树\n");
		do{
			scanf("%d", &select);
			if(select==1 || select==2)
				ThreadBinTreeAddNode(parent,node,select);
		} while(select!=1 && select!=2);
	}
	return;
}

void ThreadBinTreeTest() {
	ThreadBinTree *root=NULL; //root为指向二叉树根结点的指针
	int select;
	void (*oper1)();
	oper1=ThreadOper;
	do{
		printf("\n1.设置二叉树根元素    2.添加二叉树结点\n");
		printf("3.生成中序线索二叉树  4.遍历线索二叉树\n");
		printf("0.退出\n");
		scanf("%d", &select);
		switch(select){
		case 1:
			 root=ThreadInitRoot();
			 break;
		case 2:
			 ThreadAddNode(root);
			 break;
		case 3:
			 ThreadBinTreeThreading_LDR(root);
			 printf("\n生成中序线索二叉树完毕！\n");
			 break;
		case 4:
			 printf("\n中序线索二叉树遍历的结果：");
			 ThreadBinaryTree_LDR(root,oper1);
			 printf("\n");
			 break;
		case 0:
			 break;
		}
	} while(select != 0);
	ThreadBinTreeClear(root);
	root=NULL;
}
