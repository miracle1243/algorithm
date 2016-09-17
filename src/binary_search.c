/*
 ============================================================================
 Name        : binary_search.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : binary_search c source file
 ============================================================================
 */

#include <stdio.h>
#include "binary_search.h"

int BinarySearch(int s[],int n,int key) {
	int low, high, mid;
	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (s[mid] == key) {
			return mid;
		} else if (s[mid] > key) {
			high = mid - 1;
		} else if (s[mid] < key) {
			low = mid + 1;
		}
	}

	return -1;
}

void BinarySearchTest() {
	int key,i,pos;

	printf("请输入关键字:");
	scanf("%d",&key);

	pos = BinarySearch(binary_source,ARRAYLEN,key);

	printf("原数据表:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",binary_source[i]);
	printf("\n");

	if(pos >= 0)
		printf("查找成功，该关键字位于数组的第%d个位置。\n",pos);
	else
		printf("查找失败!\n");
}


