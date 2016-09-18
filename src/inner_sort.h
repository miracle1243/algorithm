/*
 ============================================================================
 Name        : inner_sort.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : inner_sort header file
 ============================================================================
 */

#ifndef INNER_SORT_H_
#define INNER_SORT_H_

#define ARRAYLEN 10

int CreateData(int arr[],int n,int min,int max);

void BubbleSort(int a[],int n);

void BubbleSort1(int a[],int n);

void BubbleSortTest();

void SelectSort(int a[],int n);

void SelectSortTest();

void ShellSort(int a[],int n);

void ShellSortTest();

int Division(int a[],int left, int right);

void QuickSort(int a[],int left,int right);

void QuickSortTest();


#endif /* INNER_SORT_H_ */
