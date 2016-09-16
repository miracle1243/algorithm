/*
 ============================================================================
 Name        : queue.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : queue c source file
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

SeqQueue *SeqQueueInit() {
	SeqQueue *q;
	if (q = (SeqQueue *) malloc(sizeof(SeqQueue))) {
		q->head = 0;
		q->tail = 0;
		return q;
	} else {
		return NULL;
	}
}

void SeqQueueFree(SeqQueue *q) {
	if (q != NULL)
		free(q);
}

int SeqQueueIsEmpty(SeqQueue *q) {
	return (q->head == q->tail);
}

int SeqQueueIsFull(SeqQueue *q) {
	return (q->tail == QUEUEMAX);
}

int SeqQueueLen(SeqQueue *q) {
	return (q->tail - q->head);
}

int SeqQueueIn(SeqQueue *q, DATA data) {
	if (q->tail == QUEUEMAX) {
		printf("队列已满！\n");
		return FALSE;
	} else {
		q->data[q->tail++] = data;
		return TRUE;
	}
}

DATA *SeqQueueOut(SeqQueue *q) {
	if (q->head == q->tail) {
		printf("\n队列已空！\n");
		return NULL;
	} else {
		return &(q->data[q->head++]);
	}
}

DATA *SeqQueuePeek(SeqQueue *q) {
	if (SeqQueueIsEmpty(q)) {
		printf("\n队列为空!\n");
		return NULL;
	} else {
		return &(q->data[q->head]);
	}
}

