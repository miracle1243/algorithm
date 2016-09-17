/*
 ============================================================================
 Name        : binary_sort_tree.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : binary_sort_tree c source file
 ============================================================================
 */

#include <stdio.h>
#include "binary_sort_tree.h"

void InsertBST(BSTree *t,int key) {
	BSTree *p, *parent, *head;

	if(!(p=(BSTree *)malloc(sizeof(BSTree)))) {
		printf("申请内存出错!\n");
		exit(0);
	}

	p->data = key;
	p->left = p->right = NULL;

	head = t;
	while (head) {
		parent = head;
		if (key < head->data) {
			head = head->left;
		} else {
			head = head->right;
		}
	}

	if (key < parent->data) {
		parent->left = p;
	} else {
		parent->right = p;
	}
}

BSTree *SearchBST(BSTree *t,int key) {
	if (!t || t->data == key) {
		return t;
	} else if (key > t->data) {
		return (SearchBST(t->right, key));
	} else {
		return (SearchBST(t->left, key));
	}
}

void CreateBST(BSTree *t,int data[],int n) {
	int i;
	t->data = data[0];
	t->left = t->right = NULL;
	for (i=1; i<n; i++) {
		InsertBST(t, data[i]);
	}
}

void BSTree_LDR(BSTree *t) {
	if(t) {
		BSTree_LDR(t->left);
		printf("%d ",t->data);
		BSTree_LDR(t->right);
	}
	return;
}

void BST_Delete(BSTree *t,int key) {
	BSTree *p, *parent, *l, *ll;
	int child = 0;
	if (!t)
		return;

	p = t;
	parent = p;
	while (p) {
		if (p->data == key) {
			if (!p->left && !p->right) {
				if (p == t) {
					free(p);
				} else if (child == 0) {
					parent->left = NULL;
					free(p);
				} else {
					parent->right = NULL;
					free(p);
				}
			} else if (!p->left && p->right) {
				if (child == 0) {
					parent->left = p->right;
				} else {
					parent->left = p->left;
				}
				free(p);
			} else if (p->left && !p->right) {
				if (child == 0) {
					parent->right = p->right;
				} else {
					parent->right = p->left;
				}
				free(p);
			} else {
				ll = p;
				l = p->right;
				while (l->left) {
					ll = l;
					l = l->left;
				}
				p->data = l->data;
				ll->left = NULL;
				free(ll);
			}
			p = NULL;
		} else if (key < p->data) {
			child = 0;
			parent = p;
			p = p->left;
		} else {
			child = 1;
			parent = p;
			p = p->right;
		}
	}
}

void BSTSearchTest() {
	int i,key;
	BSTree bst,*pos;

	printf("原数据:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",binary_sort_tree_source[i]);
	printf("\n");

	CreateBST(&bst,binary_sort_tree_source,ARRAYLEN);

	printf("遍历二叉排序树:");
	BSTree_LDR(&bst);

	BST_Delete(&bst,37);
	printf("\n删除结点后的结点:");

	BSTree_LDR(&bst);
	printf("\n请输入关键字:");
	scanf("%d",&key);

    pos=SearchBST(&bst,key);
	if(pos)
	   printf("查找成功，该结点的地址：%x\n",pos);
	else
		printf("查找失败!\n");
}




















