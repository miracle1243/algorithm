/*
 ============================================================================
 Name        : queue.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : queue header file
 ============================================================================
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define TRUE 1
#define FALSE 0

#define QUEUEMAX 15

typedef struct {
	char key[15];
	char name[20];
	int age;
} DATA;

typedef struct {
	DATA data[QUEUEMAX];
	int head;
	int tail;
} SeqQueue;

SeqQueue *SeqQueueInit();

void SeqQueueFree(SeqQueue *q);

int SeqQueueIsEmpty(SeqQueue *q);

int SeqQueueIsFull(SeqQueue *q);

int SeqQueueLen(SeqQueue *q);

int SeqQueueIn(SeqQueue *q,DATA data);

DATA *SeqQueueOut(SeqQueue *q);

DATA *SeqQueuePeek(SeqQueue *q);















#endif /* QUEUE_H_ */
