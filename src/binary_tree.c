/*
 ============================================================================
 Name        : binary_tree.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : binary_tree c source file
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "binary_tree.h"

LinkedBinTree *BinTreeInit(LinkedBinTree *node) {
	if (node != NULL) {
		return node;
	} else {
		return NULL;
	}
}

int BinTreeAddNode(LinkedBinTree *bt, LinkedBinTree *node, int n) {
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

LinkedBinTree *BinTreeLeft(LinkedBinTree *bt) {
	if(bt)
		return bt->left;
	else
		return NULL;
}

LinkedBinTree *BinTreeRight(LinkedBinTree *bt) {
	if(bt)
		return bt->right;
	else
		return NULL;
}

int BinTreeIsEmpty(LinkedBinTree *bt) {
	if(bt)
		return FALSE;
	else
		return TRUE;
}

int BinTreeDepth(LinkedBinTree *bt) {
	int dep1, dep2;
	if (bt == NULL) {
		return FALSE;
	} else {
		dep1 = BinTreeDepth(bt->left);
		dep2 = BinTreeDepth(bt->right);

		if (dep1 > dep2) {
			return dep1 + 1;
		} else {
			return dep2 + 1;
		}
	}
}

LinkedBinTree *BinTreeFind(LinkedBinTree *bt, char data) {
	LinkedBinTree *p;
	if (bt == NULL) {
		return NULL;
	} else {
		if (bt->data == data) {
			return bt;
		} else if (p=BinTreeFind(bt->left, data)) {
			return p;
		} else if (p=BinTreeFind(bt->right, data)) {
			return p;
		} else {
			 return NULL;
		}
	}
}

void BinTreeClear(LinkedBinTree *bt) {
	if(bt) {
		 BinTreeClear(bt->left);
		 BinTreeClear(bt->right);
		 free(bt);
		 bt=NULL;
	 }
	 return;
}

void BinTree_DLR(LinkedBinTree *bt, void (*oper)(LinkedBinTree *p)) {
	if (bt) {
		oper(bt);
		BinTree_DLR(bt->left, oper);
		BinTree_DLR(bt->right, oper);
	}
	return;
}

void BinTree_LDR(LinkedBinTree *bt, void (*oper)(LinkedBinTree *p)) {
	 if(bt) {
		 BinTree_LDR(bt->left,oper);
		 oper(bt);
		 BinTree_LDR(bt->right,oper);
	 }
	 return;
}

void BinTree_LRD(LinkedBinTree *bt, void (*oper)(LinkedBinTree *p)) {
	 if(bt) {
		 BinTree_LRD(bt->left,oper);
		 BinTree_LRD(bt->right,oper);
		 oper(bt);
	 }
	 return;
}

void oper(LinkedBinTree *p) {
	printf("%c ",p->data);
	return;
}

void BinTree_Level(LinkedBinTree *bt, void (*oper)(LinkedBinTree *p)) {
	LinkedBinTree *p;
	LinkedBinTree *q[QUEUE_MAXSIZE];
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

LinkedBinTree *InitRoot() {
	LinkedBinTree *node;
	if(node=(LinkedBinTree *)malloc(sizeof(LinkedBinTree))) {
		printf("\n输入根结点数据:");
		fflush(stdin);
		scanf("%c",&node->data);
		node->left=NULL;
		node->right=NULL;
		return node;
	}
	return NULL;
}

void AddNode(LinkedBinTree *bt) {
	LinkedBinTree *node, *parent;
	char data;
	int select;

	if (node=(LinkedBinTree *)malloc(sizeof(LinkedBinTree))) {
		printf("\n输入二叉树结点数据:");
		fflush(stdin);
		scanf("%c",&node->data);
		node->left=NULL;
		node->right=NULL;
	}

	 printf("输入父结点数据:");
	 fflush(stdin);
	 scanf("%c",&data);
	 parent=BinTreeFind(bt,data);
	 if(!parent) {
		 printf("未找到父结点!\n");
		 free(node);
		 return;
	 }
	 printf("1.添加到左子树\n2.添加到右子树\n");
	 do {
		 scanf("%d", &select);
		 if(select==1 || select==2)
			 BinTreeAddNode(parent,node,select);
	 } while(select!=1 && select!=2);

	 return;
}

void BinTreeTest() {
	LinkedBinTree *root=NULL;
	int select;
	void (*oper1)();
	oper1=oper;

	do {
		printf("\n1.设置二叉树根元素    2.添加二叉树结点\n");
		printf("3.先序遍历            4.中序遍历\n");
		printf("5.后序遍历            6.按层遍历\n");
		printf("7.二叉树深度          0.退出\n");
		scanf("%d", &select);
		switch(select){
			case 1: //设置根元素
				 root=InitRoot();
				 break;
			case 2: //添加结点
				 AddNode(root);
				 break;
			case 3://先序遍历
				 printf("\n先序遍历的结果：");
				 BinTree_DLR(root,oper1);
				 printf("\n");
				 break;
			case 4://中序遍历
				 printf("\n中序遍历的结果：");
				 BinTree_LDR(root,oper1);
				 printf("\n");
				 break;
			case 5://后序遍历
				 printf("\n后序遍历的结果：");
				 BinTree_LRD(root,oper1);
				 printf("\n");
				 break;
			case 6://按层遍历
				 printf("\n按层遍历的结果：");
				 BinTree_Level(root,oper1);
				 printf("\n");
				 break;
			case 7://二叉树的深度
				printf("\n二叉树深度为:%d\n",BinTreeDepth(root));
				break;
			case 0:
				 break;
		}
	} while(select!=0);

	BinTreeClear(root);
	root=NULL;
}























