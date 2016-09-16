/*
 ============================================================================
 Name        : linked_list.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : linked_list c source file
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

LinkedListType *LinkedListAddEnd(LinkedListType *head, DATA data) {
	LinkedListType *node, *h;
	if(!(node=(LinkedListType *)malloc(sizeof(LinkedListType)))) {
		printf("为保存结点数据申请内存失败！\n");
		return NULL;
	}

	node->data = data;
	node->next = NULL;
	if (head == NULL) {
		head = node;
		return head;
	}

	h = head;

	while (h->next != NULL) {
		h = h->next;
	}

	h->next = node;

	return head;
}

LinkedListType *LinkedListAddFirst(LinkedListType *head, DATA data) {
	LinkedListType *node;

	if(!(node=(LinkedListType *)malloc(sizeof(LinkedListType)))) {
		printf("为保存结点数据申请内存失败！\n");
		return NULL;
	}

	node->data = data;
	node->next = head;
	head = node;
	return head;
}

LinkedListType *LinkedListFind(LinkedListType *head, char *key) {
	LinkedListType *h;
	h = head;
	while (h) {
		if (strcmp(h->data.key, key) == 0) {
			return h;
		}
		h = h->next;
	}

	return NULL;
}

LinkedListType *LinkedListInsert(LinkedListType *head, char *findkey, DATA data) {
	LinkedListType *node, *node1;

	if(!(node=(LinkedListType *)malloc(sizeof(LinkedListType)))) {
		printf("为保存结点数据申请内存失败！\n");
		return NULL;
	}

	node->data = data;
	node1 = LinkedListFind(head, findkey);
	if (node1) {
		node->next = node1->next;
		node1->next = node;
	} else {
		free(node);
		printf("未找到插入位置！\n");
	}

	return head;
}

int LinkedListDelete(LinkedListType *head, char *key) {
	LinkedListType *node, *h;
	node = h = head;
	while (h) {
		if (strcmp(h->data.key, key) == 0) {
			node->next = h->next;
			free(h);
			return TRUE;
		} else {
			node = h;
			h = h->next;
		}
	}
	return FALSE;
}

int LinkedListLength(LinkedListType *head) {
	LinkedListType *h;
	int i = 0;
	h = head;
	while (h) {
		i++;
		h = h->next;
	}

	return i;
}

void LinkedListAll(LinkedListType *head) {
	LinkedListType *h;
	DATA data;
	h = head;

	printf("链表所有数据如下：\n");
	while (h) {
		data = h->data;
		printf("(%s,%s,%d)\n", data.key, data.name, data.age);
		h = h->next;
	}
	return;
}

void LinkedListTest() {
	LinkedListType *node, *head = NULL;
	DATA data;
	char key[15], findkey[15];

	printf("输入链表中的数据，包括关键字、姓名、年龄，关键字输入0，则退出：\n");
	do {
		fflush(stdin);
		scanf("%s", data.key);
		if (strcmp(data.key, "0") == 0)
			break;

		scanf("%s%d", data.name, &data.age);
		head = LinkedListAddEnd(head, data);

	} while (1);

	printf("该链表共有%d个结点。\n", LinkedListLength(head));
	LinkedListAll(head);

	printf("\n插入结点，输入插入位置的关键字：");
	scanf("%s", &findkey);
	printf("输入插入结点的数据(关键字 姓名 年龄):");
	scanf("%s%s%d", data.key, data.name, &data.age);
	head = LinkedListInsert(head, findkey, data);

	LinkedListAll(head);

	printf("\n在链表中查找，输入查找关键字:");
	fflush(stdin);
	scanf("%s", key);
	node = LinkedListFind(head, key);
	if (node) {
		data = node->data;
		printf("关键字%s对应的结点数据为(%s,%s,%d)\n", key, data.key, data.name, data.age);

	} else {
		printf("在链表中未找到关键字为%s的结点！\n", key);
	}

	printf("\n在链表中删除结点，输入要删除的关键字:");
	fflush(stdin);
	scanf("%s", key);
	LinkedListDelete(head, key);

	LinkedListAll(head);

}

