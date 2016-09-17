/*
 ============================================================================
 Name        : binary_sort_tree.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : binary_sort_tree header file
 ============================================================================
 */

#ifndef BINARY_SORT_TREE_H_
#define BINARY_SORT_TREE_H_

#define ARRAYLEN 10
int binary_sort_tree_source[]={54,90,6,69,12,37,92,28,65,83};

typedef struct bst {
	int data;
	struct bst *left;
	struct bst *right;
} BSTree;

void InsertBST(BSTree *t,int key);

BSTree *SearchBST(BSTree *t,int key);

void CreateBST(BSTree *t,int data[],int n);

void BSTree_LDR(BSTree *t);

void BST_Delete(BSTree *t,int key);

void BSTSearchTest();


#endif /* BINARY_SORT_TREE_H_ */
