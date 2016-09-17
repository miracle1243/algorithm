/*
 ============================================================================
 Name        : seq_search.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : seq_search c source file
 ============================================================================
 */

#include <stdio.h>
#include "seq_search.h"

int SeqSearch(int s[],int n,int key) {
	int i;
	for (i=0; s[i]!=key; i++) {
		;
	}
	if (i < n) {
		return i;
	} else {
		return -1;
	}
}

void SeqSearchTest() {
	int key,i,pos;

	printf("请输入关键字:");
	scanf("%d",&key);

	pos = SeqSearch(seq_source,ARRAYLEN,key);

	printf("原数据表:");
	for(i=0; i<ARRAYLEN; i++) {
		printf("%d ",seq_source[i]);
	}
	printf("\n");

	if(pos>=0)
		printf("查找成功，该关键字位于数组的第%d个位置。\n",pos);
	else
		printf("查找失败!\n");

}




















