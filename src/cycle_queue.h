/*
 ============================================================================
 Name        : cycle_queue.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : cycle queue header file
 ============================================================================
 */

#ifndef CYCLE_QUEUE_H_
#define CYCLE_QUEUE_H_

#define TRUE 1
#define FALSE 0

#define QUEUEMAX 15

typedef struct {
	int num;
	long time;
} QueueData;

typedef struct {
	QueueData data[QUEUEMAX];
	int head;
	int tail;
} CycQueue;

CycQueue *CycQueueInit();

void CycQueueFree(CycQueue *q);

int CycQueueIsEmpty(CycQueue *q);

int CycQueueIsFull(CycQueue *q);

int CycQueueIn(CycQueue *q, QueueData data);

QueueData *CycQueueOut(CycQueue *q);

int CycQueueLen(CycQueue *q);

QueueData *CycQueuePeek(CycQueue *q);

void CycQueueTest();

void add(CycQueue *q);

void next(CycQueue *q);

#endif /* CYCLE_QUEUE_H_ */
