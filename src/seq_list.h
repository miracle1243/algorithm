/*
 ============================================================================
 Name        : seq_list.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : seq_list header file
 ============================================================================
 */

#ifndef SEQ_LIST_H_
#define SEQ_LIST_H_

#define MAXSIZE 100
#define FALSE 0
#define TRUE 1

typedef struct {
	char key[15];
	char name[20];
	int age;
} DATA;

typedef struct {
	DATA ListData[MAXSIZE + 1];
	int ListLen;
} SeqListType;

void SeqListInit(SeqListType *SL);

int SeqListLength(SeqListType *SL);

int SeqListAdd(SeqListType *SL, DATA data);

int SeqListInsert(SeqListType *SL, int n, DATA data);

int SeqListDelete(SeqListType *SL,int n);

DATA *SeqListFindByNum(SeqListType *SL, int n);

int SeqListFindByCont(SeqListType *SL, char *key);

int SeqListAll(SeqListType *SL);

void SeqListTest();

#endif /* SEQ_LIST_H_ */
