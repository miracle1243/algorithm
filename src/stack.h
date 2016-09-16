/*
 ============================================================================
 Name        : stack.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : stack header file
 ============================================================================
 */

#ifndef STACK_H_
#define STACK_H_

#define TRUE 1
#define FALSE 0
#define SIZE 50

typedef struct {
	char name[15];
	int age;
} StackData;

typedef struct stack {
	StackData data[SIZE + 1];
	int top;
} SeqStack;

SeqStack *SeqStackInit();

int SeqStackIsEmpty(SeqStack *s);

void SeqStackFree(SeqStack *s);

void SeqStackClear(SeqStack *s);

int SeqStackIsFull(SeqStack *s);

int SeqStackPush(SeqStack *s, StackData data);

StackData SeqStackPop(SeqStack *s);

StackData SeqStackPeek(SeqStack *s);

void SeqStackTest();

#endif /* STACK_H_ */
