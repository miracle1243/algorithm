/*
 ============================================================================
 Name        : main.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : c main file
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	setbuf(stderr, NULL);

	/**
	 * 1.枚举算法思想例子
	 */
	//chicken();
	//number();

	/*
	 * 2.递推算法思想例子
	 */
	//shuntui();
	//nitui();

	/**
	 * 3.递归算法思想例子
	 */
	//hanoi();
	//factorial();

	/**
	 * 4.分治算法思想例子
	 */
	//divide();
	game_schedule();


	return EXIT_SUCCESS;
}
