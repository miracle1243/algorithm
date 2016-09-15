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
	//game_schedule();

	/**
	 * 5.贪心算法思想例子
	 */
	//install_box();

	/**
	 * 6.试探法算法思想例子
	 */
	//eight_queen();
	//lottery_combine();

	/**
	 * 7.动态规划算法思想例子
	 */
	//max_sequence();

	/**
	 * 8.迭代算法思想例子
	 */
	//square();

	/**
	 * 9.模拟算法思想例子
	 */
	guess_number();

	return EXIT_SUCCESS;
}
