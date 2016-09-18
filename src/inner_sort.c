/*
 ============================================================================
 Name        : inner_sort.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : inner_sort c source file
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inner_sort.h"

int CreateData(int arr[],int n,int min,int max) {
    int i,j,flag;
    srand(time(NULL));

    if((max-min+1)<n)
    	return 0;

    for(i=0;i<n;i++) {
    	do {
            arr[i] = (max-min+1)*rand()/(RAND_MAX+1)+min;
            flag = 0;
            for(j=0;j<i;j++) {
                if(arr[i]==arr[j])
                    flag=1;
            }
        } while(flag);
    }
    return 1;
}

void BubbleSort(int a[],int n)
{
    int i,j,t;

    for(i=0; i<n-1; i++) {
        for(j=n-1; j>i; j--) {
            if(a[j-1]>a[j]) {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
        }
        printf("第%2d遍:",i+1);
        for(j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
    }
}

void BubbleSort1(int a[],int n)
{
    int i,j,t,flag = 0;

    for(i=0;i<n-1;i++) {
        for(j=n-1;j>i;j--) {
            if(a[j-1]>a[j]) {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                flag=1;
            }
        }
        printf("第%2d遍:",i+1);
        for(j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
        if(flag == 0)
            break;
        else
            flag=0;
    }
}

void BubbleSortTest() {
	int i,a[ARRAYLEN];

	for(i=0;i<ARRAYLEN;i++)
		a[i]=0;

	if(!CreateData(a,ARRAYLEN,1,100)) {
		printf("生成随机数不成功!\n");
		exit(0);
	}
	printf("原数据:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",a[i]);
	printf("\n");

	BubbleSort1(a,ARRAYLEN);

	printf("排序后:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void SelectSort(int a[],int n) {
    int i,j,t,k;
    for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++)
			if(a[k]>a[j]) k=j;
		t=a[i];
		a[i]=a[k];
		a[k]=t;
    }
}

void SelectSortTest() {
	int i,a[ARRAYLEN];

	for(i=0;i<ARRAYLEN;i++)
		a[i]=0;

	if(!CreateData(a,ARRAYLEN,1,100))  {
		printf("生成随机数不成功!\n");
		exit(0);
	}

	printf("原数据:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",a[i]);
	printf("\n");

	SelectSort(a,ARRAYLEN);

	printf("排序后:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void ShellSort(int a[],int n) {
    int d,i,j,x;
    d=n/2;

    while(d>=1) {
		for(i=d;i<n;i++) {
			x=a[i];
			j=i-d;

			while(j>=0 && a[j]>x) {
				a[j+d]=a[j];
				j=j-d;
			}
			a[j+d]=x;
		}
		d/=2;
    }
}

void ShellSortTest() {
	int i,a[ARRAYLEN];
	for(i=0;i<ARRAYLEN;i++)
		a[i]=0;

	if(!CreateData(a,ARRAYLEN,1,100)) {
		printf("生成随机数不成功!\n");
		exit(0);
	}

	printf("原数据:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",a[i]);
	printf("\n");

	ShellSort(a,ARRAYLEN);

	printf("排序后:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int Division(int a[],int left, int right) {
    int base=a[left];

    while(left < right) {
        while(left<right && a[right]>base)
            --right;
        a[left]=a[right];

        while(left<right && a[left]<base )
            ++left;
        a[right]=a[left];
    }

    a[left]=base;
    return left;
}

void QuickSort(int a[],int left,int right) {
    int i,j;

    if(left<right) {
        i=Division(a,left,right);
        QuickSort(a,left,i-1);
        QuickSort(a,i+1,right);
    }
}

void QuickSortTest() {
	int i,a[ARRAYLEN];
	for(i=0;i<ARRAYLEN;i++)
		a[i]=0;

	if(!CreateData(a,ARRAYLEN,1,100)) {
		printf("生成随机数不成功!\n");
		exit(0);
	}

	printf("原数据:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",a[i]);
	printf("\n");

	QuickSort(a,0,ARRAYLEN-1);

	printf("排序后:");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",a[i]);
	printf("\n");
}













