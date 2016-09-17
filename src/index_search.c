/*
 ============================================================================
 Name        : index_search.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : index_search c source file
 ============================================================================
 */

#include <stdio.h>
#include "index_search.h"

int IndexSearch(int key) {
	int i,index1,start,length;
	index1=key/100;

	for(i=0;i<INDEXTABLE_LEN;i++) {
		if(indextable[i].index==index1) {
			start=indextable[i].start;
			length=indextable[i].length;
			break;
		}
	}
	if(i >= INDEXTABLE_LEN)
		return -1;

	for(i=start;i<start+length;i++) {
		if(stu[i]==key)
			return i;
	}
	return -1;
}

void IndexSearchTest() {
	long key;
	int i,pos;
	printf("原数据:");
	for(i=0;i<INDEX_TABLE_LEN;i++)
		printf("%ld ",stu[i]);
	printf("\n");

	printf("输入查找关键字:");
	scanf("%ld",&key);

	pos = IndexSearch(key);
	if(pos>0)
		printf("查找成功,该关键字位于数组的第%d个位置。\n",pos);
	else
		printf("查找失败!\n");
}
