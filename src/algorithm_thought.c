/*
 ============================================================================
 Name        : algorithm_thought.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : some kinds of algorithm thought
 ============================================================================
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "algorithm_thought.h"

char *result = '\0';
int pr = 1;
int a[MAXN+1][MAXN+1] = {0};

/**
 * 百元买鸡
 */
void chicken() {
	int x, y, z;

	for (x = 0; x <= 20; x++) {
		for (y = 0; y <= 33; y++) {
			z = 100 - x - y;
			if (z % 3 == 0 && x * 5 + y * 3 + z / 3 == 100) {
				printf("公鸡：%d, 母鸡：%d, 小鸡：%d\n", x, y, z);
			}
		}
	}
}

/**
 * 5 5 5 5 5 = 5
 */
void number() {
	int j, i[5];
	int sign;
	int result;
	int count = 0;
	int num[6];
	float left, right;
	char oper[5] = { ' ', '+', '-', '*', '/' };

	printf("请输入5个数：");
	for (j = 1; j <= 5; j++) {
		scanf("%d", &num[j]);
	}

	printf("请输入结果：");
	scanf("%d", &result);

	for (i[1] = 1; i[1] <= 4; i[1]++) {
		if ((i[1] < 4) || (num[2] != 0)) {
			for (i[2] = 1; i[2] <= 4; i[2]++) {
				if ((i[2] < 4) || (num[3] != 0)) {
					for (i[3] = 1; i[3] <= 4; i[3]++) {
						if ((i[3] < 4) || (num[4] != 0)) {
							for (i[4] = 1; i[4] <= 4; i[4]++) {
								if ((i[4] < 4) || (num[5] != 0)) {
									left = 0;
									right = num[1];
									sign = 1;
									for (j = 1; j <= 4; j++) {
										switch (oper[i[j]]) {
										case '+':
											left = left + sign * right;
											sign = 1;
											right = num[j + 1];
											break;
										case '-':
											left = left + sign * right;
											sign = -1;
											right = num[j + 1];
											break;
										case '*':
											right = right * num[j + 1];
											break;
										case '/':
											right = right / num[j + 1];
											break;
										}
									}
									if (left+sign*right == result) {
										count++;
										printf("3%d: ", count);
										for (j=1; j<=4; j++) {
											printf("%d%c", num[j], oper[i[j]]);
										}
										printf("%d=%d\n", num[5], result);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (count == 0) {
		printf("没有符合要求的方法!\n");
	}
}

/**
 * 递推算法——顺推法
 */
void shuntui() {
	int i;
	long fib[NUM] = {1,1};

	for (i=2; i<NUM; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	for (i=0; i<NUM; i++) {
		printf("%d月兔子总数：%d\n", i, fib[i]);
	}
}

/**
 * 递推算法——逆推法
 */
void nitui() {

	double corpus[49];
	int i;
	corpus[48] = (double)FETCH;

	for (i=47; i>0; i--) {
		corpus[i] = (corpus[i+1]+FETCH)/(1+RATE/12);
	}

	for (i = 48; i > 0; i--) {
		printf("第%d月末本利合计：%.2f\n", i, corpus[i]);
	}
}

/**
 * 递推算法
 */
void hanoi() {
	int h;
	printf("input number: ");
	scanf("%d", &h);
	printf("the step to moving %2d diskes: \n", h);
	move(h, 'a', 'b', 'c');
}

void move(int n, int x, int y, int z) {
	if (n == 1) {
		printf("%C-->%C\n", x, z);
	} else {
		move(n-1, x, z, y);
		printf("%C-->%C\n", x, z);
		move(n-1, y, x, z);
	}
}

/**
 * 阶乘
 */
void factorial() {
	int i;
	printf("请输入要求阶乘的一个整数：");
	scanf("%d", &i);
	printf("%d阶乘结果为：%d\n", i, fact(i));
}

int fact(int n) {
	if (n<=1) {
		return 1;
	} else {
		 return n*fact(n-1);
	}
}

/**
 *分治算法——大数相乘
 */
void divide() {
	char *a, *b;
	int n, flag;

	a = (char *)malloc(1000);
	b = (char *)malloc(1000);
	printf("The program will computer a*b\n");
	printf("Enter a b :");
	scanf("%s %s", a, b);
	result = (char *)malloc(strlen(a) + strlen(b) + 2);
	flag = pr = 1;
	result[0] = '\0';

	if (a[0] == '-' && b[0] == '-') {
		get(a, b, 1, strlen(a)-1, 1, strlen(b)-1, 1, 0);
	}
	if (a[0] == '-' && b[0] != '-') {
		flag = 0;
		get(a, b, 1, strlen(a)-1, 0, strlen(b)-1, 1, 0);
	}
	if (a[0] != '-' && b[0] == '-') {
		flag = 0;
		get(a, b, 0, strlen(a)-1, 1, strlen(b)-1, 1, 0);
	}

	if (a[0] != '-' && b[0] != '-') {
		get(a, b, 0, strlen(a)-1, 0, strlen(b)-1, 1, 0);
	}

	if (!flag) {
		printf("-");
	}
	if (result[0]) {
		printf("%d", result[0]);

	}
	for (n=1; n < pr; n++) {
		printf("%d", result[n]);
	}
	printf("\n");
	free(a);
	free(b);
	free(result);


}

void getFill(char *a, char *b, int ia, int ja, int ib, int jb, int tbool, int move) {
	int r, m, n, s, j, t;
	char *stack;

	m = a[ia] - 48;
	if (tbool) {
		r = (jb - ib > ja - ia) ? (jb - ib) : (ja - ia);
		stack = (char *)malloc(r + 4);
		for (r=j=0, s=jb; s>= ib; r++,s--) {
			n = b[s] - 48;
			stack[r] = (m*n+j)%10;
			j = (m*n+j)/10;
		}
		if (j) {
			stack[r] = j;
			r++;
		}
		for (r--;r>=0;r--,pr++) {
			result[pr] = stack[r];
		}
		free(stack);
		for (move=move+pr; pr<move; pr++) {
			result[pr] = '\0';
		}
	} else {
		r = pr - move - 1;
		for (s=jb,j=0; s>=ib; r--, s--) {
			n = b[s] - 48;
			t = m*n +j +result[r];
			result[r] = t % 10;
			j = t / 10;
		}
		for (;j;r--) {
			t = j + result[r];
			result[r] = t % 10;
			j = t / 10;
		}
	}
}

int get(char *a, char *b, int ia, int ja, int ib, int jb, int t, int move) {
	int m, n, s, j;

	if (ia == ja) {
		getFill(a, b, ia, ib, ib, jb, t, move);
		return 1;
	} else if (ib == jb) {
		getFill(b, a, ib, jb, ia, ja, t, move);
		return 1;
	} else {
		m = (ja + ia) / 2;
		n = (jb + ib) / 2;
		s = ja - m;
		j = jb - n;
		get(a, b, ia, m, ib, n, t, s+j+move);
		get(a, b, ia, m, n+1, jb, 0, s+move);
		get(a, b, m+1, ja, ib, n, 0, j+move);
		get(a, b, m+1, ja, n+1, jb, 0, 0+move);
	}
	return 0;
}

/**
 * 分治算法——比赛安排
 */
void game_schedule() {
	int m, i, j;
	printf("输入参赛球队数：");
	scanf("%d", &m);
	j = 2;
	for (i=2; i<8; i++) {
		j = j*2;
		if (j==m) {
			break;
		}
	}
	if (i>=8) {
		printf("参赛球队数必须为2的整数次幂，且不超过64！\n");
		return;
	}

	gamecal(1,m);
	printf("\n球队编号");
	for (i=2;i<=m;i++) {
		printf("%2d天",i-1);
	}
	printf("\n");

	for (i=1;i<=m;i++) {
		for (j=1;j<=m;j++) {
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}
}

void gamecal(int k, int n) {
	int i, j;
	if (n == 2) {
		a[k][1] = k;
		a[k][2] = k+1;
		a[k+1][1] = k+1;
		a[k+1][2] = k;
	} else {
		gamecal(k, n/2);
		gamecal(k+n/2, n/2);
		for (i=k; i<k+n/2; i++) {
			for (j=n/2+1;j<=n;j++) {
				a[i][j] = a[i+n/2][j-n/2];
			}
		}
		for (i=k+n/2;i<k+n;i++) {
			for (j=n/2+1;j<=n;j++) {
				a[i][j] = a[i-n/2][j-n/2];
			}
		}
	}
}






