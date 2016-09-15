/*
 ============================================================================
 Name        : algorithm_thought.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : algorithm_thought header file
 ============================================================================
 */

#ifndef ALGORITHM_THOUGHT_H_
#define ALGORITHM_THOUGHT_H_

//枚举算法思想
void chicken();

void number();

//递推算法思想
#define NUM 13

void shuntui();

#define FETCH 1000
#define RATE 0.0171

void nitui();

//递归算法思想
void hanoi();

void move(int n, int x, int y, int z);

void factorial();

int fact(int n);

//分治算法思想
void divide();

void getFill(char *a, char *b, int ia, int ja, int ib, int jb, int tbool, int move);

int get(char *a, char *b, int ia, int ja, int ib, int jb, int t, int move);

void game_schedule();

#define MAXN 64
void gamecal(int k, int n);

//贪心算法思想
<<<<<<< HEAD
void install_box();

#define N 6
#define V 100

typedef struct box {
	int no;
	int size;
	struct box* next;
} BOX;

void init_list(BOX** H);

BOX* find_p(BOX* H, int volume, int v);

void add_list_tail(BOX* H, BOX* p);

void print_list(BOX* H);

int add_box(int volumn[], int v);

//试探法算法思想
void eight_queen();

#define NN 8

int place(int row, int col);

void backtrack(int row);

void queens();

#define MAXNN 7
#define NUMM 29

void lottery_combine();

void combine(int n, int m);


//动态规划算法思想
void max_sequence();

#define MAXLEN 100

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN]);

void PrintLCS(int b[][MAXLEN], char *x, int i, int j);

//迭代算法思想
void square();

//模拟算法思想
void guess_number();


#endif /* ALGORITHM_THOUGHT_H_ */
