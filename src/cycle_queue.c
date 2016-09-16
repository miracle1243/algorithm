/*
 ============================================================================
 Name        : cycle_queue.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : cycle queue c source file
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cycle_queue.h"

int customer;

CycQueue *CycQueueInit() {
	CycQueue *q;

	if (q = (CycQueue *) malloc(sizeof(CycQueue))) {
		q->head = 0;
		q->tail = 0;
		return q;
	} else {
		return NULL;
	}
}

void CycQueueFree(CycQueue *q) {
	if (q != NULL) {
		free(q);
	}
}

int CycQueueIsEmpty(CycQueue *q) {
	return (q->head == q->tail);
}

int CycQueueIsFull(CycQueue *q) {
	return ((q->tail + 1) % QUEUEMAX == q->head);
}

int CycQueueIn(CycQueue *q, QueueData data) {
	if ((q->tail + 1) % QUEUEMAX == q->head) {
		printf("队列已满！\n");
		return FALSE;
	} else {
		q->tail = (q->tail + 1) % QUEUEMAX;
		q->data[q->tail] = data;
		return TRUE;
	}
}

QueueData *CycQueueOut(CycQueue *q) {
	if (q->head == q->tail) {
		printf("队列已空！\n");
		return NULL;
	} else {
		q->head = (q->head + 1) % QUEUEMAX;
		return &(q->data[q->head]);
	}
}

int CycQueueLen(CycQueue *q) {
	int n;
	n = q->tail - q->head;
	if (n < 0)
		n = QUEUEMAX + n;
	return n;
}

QueueData *CycQueuePeek(CycQueue *q) {
	if (q->head == q->tail) {
		printf("队列已空！\n");
		return NULL;
	} else {
		return &(q->data[(q->head + 1) % QUEUEMAX]);
	}
}

void CycQueueTest() {
	CycQueue *queue1;
	char select;
	customer = 0;
	queue1 = CycQueueInit();
	if (queue1 == NULL) {
		printf("创建队列时出错！\n");
	}

	do {
		printf("\n请选择具体操作:\n");
		printf("1.新到顾客\n");
		printf("2.下一个顾客\n");
		printf("0.退出\n") ;
		fflush(stdin);

		scanf("%c", &select);
		switch(select) {
			case '1':
				add(queue1);
				printf("\n现在共有%d位顾客在等候!\n",CycQueueLen(queue1));
				break;
			case '2':
				next(queue1);
				printf("\n现在共有%d位顾客在等候!\n",CycQueueLen(queue1));
				break;
			case '0':
				break;
		}
	} while (select != '0');

	CycQueueFree(queue1); //释放队列
}

void add(CycQueue *q) {
	QueueData data;
	if (!CycQueueIsFull(q)) {
		data.num = ++customer;
		data.time = time(NULL);
		CycQueueIn(q, data);
	} else {
		printf("\n排队的人太多，请稍候再排队!\n");
	}
}

void next(CycQueue *q) {
	QueueData *data;
	if (!CycQueueIsEmpty(q)) {
		data = CycQueueOut(q);
		printf("\n请编号为%d的顾客办理业务!\n", data->num);
	}
	if (!CycQueueIsEmpty(q)) {
		data = CycQueuePeek(q);
		printf("请编号为%d的顾客准备，马上将为您理业务!\n", data->num);
	}
}

