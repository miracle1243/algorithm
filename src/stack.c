/*
 ============================================================================
 Name        : stack.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : stack c source file
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

SeqStack *SeqStackInit() {
	SeqStack *p;
	if (p=(SeqStack *)malloc(sizeof(SeqStack))) {
		p->top = 0;
		return p;
	}

	return NULL;
}

int SeqStackIsEmpty(SeqStack *s) {
	 return(s->top == 0);
}

void SeqStackFree(SeqStack *s) {
	if (s) {
		free(s);
	}
}

void SeqStackClear(SeqStack *s) {
	s->top = 0;
}

int SeqStackIsFull(SeqStack *s) {
	return(s->top == SIZE);
}

int SeqStackPush(SeqStack *s,StackData data) {
	if((s->top+1)>SIZE) {
		 printf("栈溢出!\n");
		 return FALSE;
	 }
	 s->data[++s->top] = data;//将元素入栈
	 return TRUE;
}

StackData SeqStackPop(SeqStack *s) {
	 if(s->top==0) {
		 printf("栈为空！");
		 exit(0);
	 }
	 return (s->data[s->top--]);
}

StackData SeqStackPeek(SeqStack *s) {
	if(s->top==0) {
		 printf("栈为空！");
		 exit(0);
	 }
	 return (s->data[s->top]);
}

void SeqStackTest() {
	SeqStack *stack;
	StackData data,data1;
	stack=SeqStackInit();  //初始化栈
	printf("入栈操作：\n");
	printf("输入姓名 年龄进行入栈操作:");
	scanf("%s%d",data.name,&data.age);
	SeqStackPush(stack,data);
	printf("输入姓名 年龄进行入栈操作:");
	scanf("%s%d",data.name,&data.age);
	SeqStackPush(stack,data);
	printf("\n出栈操作：\n");

	data1=SeqStackPop(stack);
	printf("出栈的数据是(%s,%d)\n" ,data1.name,data1.age);

	data1=SeqStackPop(stack);
	printf("出栈的数据是(%s,%d)\n" ,data1.name,data1.age);
	SeqStackFree(stack);
}

