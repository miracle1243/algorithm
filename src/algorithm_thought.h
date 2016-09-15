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

//试探法算法思想

//动态规划算法思想

//迭代算法思想

//模拟算法思想


#endif /* ALGORITHM_THOUGHT_H_ */
