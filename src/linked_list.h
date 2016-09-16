/*
 ============================================================================
 Name        : linked_list.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : linked_list header file
 ============================================================================
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef struct {
	char key[15];
	char name[20];
	int age;
} DATA;

typedef struct Node {
	DATA data;
	struct Node *next;
} LinkedListType;

LinkedListType *LinkedListAddEnd(LinkedListType *head, DATA data);

LinkedListType *LinkedListAddFirst(LinkedListType *head, DATA data);

LinkedListType *LinkedListFind(LinkedListType *head, char *key);

LinkedListType *LinkedListInsert(LinkedListType *head, char *findkey, DATA data);

int LinkedListDelete(LinkedListType *head, char *key);

int LinkedListLength(LinkedListType *head);

void LinkedListAll(LinkedListType *head);

void LinkedListTest();

#endif /* LINKED_LIST_H_ */

