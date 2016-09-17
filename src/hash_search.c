/*
 ============================================================================
 Name        : hash_search.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : hash_search c source file
 ============================================================================
 */
#include <stdio.h>
#include "hash_search.h"

void InsertHash(int hash[],int m,int data) {
	int i;
	i = data % 13;
	while (hash[i]) {
		i = (++i) % m;
	}
	hash[i] = data;
}

void CreateHash(int hash[],int m,int data[],int n) {
	int i;
	for (i=0; i<n; i++) {
		InsertHash(hash, m, data[i]);
	}
}

int HashSearch(int hash[],int m,int key) {
	int i;
	i = key % 13;
	while (hash[i] && hash[i] != key) {
		i = (++i) % m;

	}
	if (hash[i] == 0) {
		return -1;
	} else {
		return i;
	}

}

void HashSearchTest() {
	int key,i,pos;

	CreateHash(hash,HASH_LEN,hash_data,TABLE_LEN);

	printf("哈希表各元素的值:");
	for(i=0;i<HASH_LEN;i++)
		printf("%ld ",hash[i]);
	printf("\n");

	printf("输入查找关键字:");
	scanf("%ld",&key);

	pos = HashSearch(hash,HASH_LEN,key);
	if(pos>0)
		printf("查找成功,该关键字位于数组的第%d个位置。\n",pos);
	else
		printf("查找失败!\n");
}

















