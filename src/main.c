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
	//guess_number();

	/**
	 *线性表例子
	 */
	//SeqListTest();

	/**
	 * 链表例子
	 */
	//LinkedListTest();

	/**
	 * 循环队列例子
	 */
	//CycQueueTest();

	/**
	 * 栈例子
	 */
	//SeqStackTest();

	/**
	 * 二叉树例子
	 */
	//BinTreeTest();

	/**
	 * 线索二叉树例子
	 */
	//ThreadBinTreeTest();

	/**
	 * 赫夫曼树例子
	 */
	//HuffmanTreeTest();

	/**
	 * 顺序查找例子
	 */
	//SeqSearchTest();

	/**
	 * 折半查找例子
	 */
	//BinarySearchTest();

	/**
	 * 二叉排序树查找
	 */
	//BSTSearchTest();

	/**
	 * 哈希查找例子
	 */
	//HashSearchTest();

	/**
	 * 索引查找例子
	 */
	//IndexSearchTest();

	/**
	 * 冒泡排序例子
	 */
	//BubbleSortTest();

	/**
	 * 选择排序例子
	 */
	//SelectSortTest();

	/**
	 * 希尔排序例子
	 */
	//ShellSortTest();

	/**
	 * 快速排序例子
	 */
	//QuickSortTest();

	/**
	 * 归并排序例子
	 */
	//MergeSortTest();

	/**
	 * 堆排序例子
	 */
	HeapSortTest();

	return EXIT_SUCCESS;
}
