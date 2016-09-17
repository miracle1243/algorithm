/*
 ============================================================================
 Name        : hash_search.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : hash_search header file
 ============================================================================
 */

#ifndef HASH_SEARCH_H_
#define HASH_SEARCH_H_

#define HASH_LEN 13
#define TABLE_LEN 8

int hash_data[TABLE_LEN]={69,65,90,37,92,6,28,54};
int hash[HASH_LEN]={0};

void InsertHash(int hash[],int m,int data);

void CreateHash(int hash[],int m,int data[],int n);

int HashSearch(int hash[],int m,int key);

void HashSearchTest();


#endif /* HASH_SEARCH_H_ */
