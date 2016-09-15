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
#include <math.h>
#include <time.h>
#include "algorithm_thought.h"

char *result = '\0';
int pr = 1;
int a[MAXN+1][MAXN+1] = {0};
int solution[NN], sols;
int num[NUM], lottery[MAXNN];

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

/**
 *贪心算法——装箱问题
 */
void init_list(BOX** H) {
	*H = (BOX*)malloc(sizeof(BOX));
	(*H)->no = 0;
	(*H)->size = 0;
	(*H)->next = NULL;
}

BOX* find_p(BOX* H, int volume, int v) {
	BOX* p = H->next;
	while (p != NULL) {
		if (p->size+volume <= v)
			break;
		p = p->next;
	}

	return p;
}

void add_list_tail(BOX* H, BOX* p) {
	BOX* tmp = H->next;
	BOX* q = H;

	while (tmp != NULL) {
		q = tmp;
		tmp = tmp->next;
	}

	q->next = p;
}

void print_list(BOX* H) {
	BOX* p = H->next;
	while (p != NULL) {
		printf("%d:%d\n", p->no, p->size);
		p = p->next;
	}
}

int add_box(int volumn[], int v) {
	int count = 0;
	int i;
	BOX* H = NULL;

	init_list(&H);

	for (i=0; i<N; i++) {
		BOX* p = find_p(H, volumn[i], v);
		if (p == NULL) {
			count++;
			p = (BOX*)malloc(sizeof(BOX));
			p->no = count;
			p->size = volumn[i];
			p->next = NULL;
			add_list_tail(H, p);
		} else {
			p->size += volumn[i];
		}
	}

	print_list(H);

	return count;
}

void install_box() {
	int ret;
	int volumes[] = {60, 45, 35, 20, 20, 20};

	ret = add_box(volumes, V);

	printf("%d\n", ret);

}

/**
 * 试探法算法——八皇后问题
 */
void eight_queen() {
	queens();
	printf("Total Solutions: %d\n", sols);
}

int place(int row, int col) {
	int j;
	for (j=0; j<row; j++) {
		if (row-j == solution[row] - solution[j]
				|| row+solution[row] == j+solution[j]
				|| solution[j] == solution[row]) {
			return 0;
		}
	}
	return 1;
}

void backtrack(int row) {
	int count=0;
	int k;
	count++;
	if (NN == row) {
		sols++;
		for (k=0;k<NN;k++) {
			printf("%d\t", solution[k]);
		}
		printf("\n\n");
	} else {
		int i;
		for (i=0; i<NN; i++) {
			solution[row] = i;
			if (place(row, i)) {
				backtrack(row+1);
			}
		}
	}
}

void queens() {
	backtrack(0);
}

void lottery_combine() {
	int i;
	for (i=0; i<NUMM; i++) {
		num[i]=i+1;
	}
	for (i=0;i<MAXNN;i++) {
		lottery[i] = 0;
	}
	combine(NUMM, MAXNN);
}

void combine(int n, int m) {
	int i, j;
	for (i=n; i>=m; i--) {
		lottery[m-1] = num[i-1];
		if (m>1) {
			combine(i-1,m-1);
		} else {
			for (j=MAXNN-1; j>=0; j--) {
				printf("%3d", lottery[j]);
			}
			printf("\n");
		}
	}
}

/**
 * 动态规划算法——最长公共子序列
 */
void max_sequence() {
	char x[MAXLEN] = {"ABCBDAB"};
	char y[MAXLEN] = {"BDCABA"};
	int b[MAXLEN][MAXLEN];
	int c[MAXLEN][MAXLEN];
	int m, n;

	m = strlen(x);
	n = strlen(y);

	LCSLength(x, y, m, n, c, b);
	PrintLCS(b, x, m, n);
}

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN]) {
	int i, j;

	for (i=0; i<=m; i++) {
		c[i][0] = 0;
	}
	for (j=1; j<=n; j++) {
		c[0][j] = 0;
	}
	for (i=1; i<=m; i++) {
		for (j=1; j<=n; j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i][j-1] + 1;
				b[i][j] = 0;
			} else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 1;
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = -1;
			}
		}
	}
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j) {
	 if (i == 0 || j == 0) {
		 return;
	 }
	 if (b[i][j] == 0) {
		 PrintLCS(b, x, i-1, j-1);
		 printf("%c ", x[i-1]);
	 } else if (b[i][j] == 1) {
		 PrintLCS(b, x, i-1, j);
	 } else {
		 PrintLCS(b, x, i, j-1);
	 }
}

/**
 * 迭代算法——求平方根
 */
void square() {
	double a, x0, x1;
	printf("Input a num: \n");
	scanf("%lf", &a);
	if (a<0) {\
		printf("Error!\n");
	} else {
		x0 = a/2;
		x1= (x0+a/x0)/2;
		do {
			x0 = x1;
			x1 = (x0+a/x0)/2;
		} while (fabs(x0-x1) >= 1e-6);
	}
	printf("Result:\n");
	printf("sqrt(%g)=%g\n", a, x1);
}

/**
 * 模拟算法——猜数
 */
void guess_number() {
	int n, m, i=0;
	srand(time(NULL));
	n = rand() % 100 + 1;
	do {
		printf("输入所猜的数字：");
		scanf("%d", &m);
		i++;
		if (m>n) {
			printf("错误!所猜的数太大了!\n");
		} else if (m<n) {
			printf("错误!所猜的数太小了!\n");
		}
	} while (m!=n);

	printf("答对了!\n");
	printf("共猜测了%d次。\n", i);
}

