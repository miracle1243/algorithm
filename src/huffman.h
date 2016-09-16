/*
 ============================================================================
 Name        : huffman.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : huffman header file
 ============================================================================
 */

#ifndef HUFFMAN_C_
#define HUFFMAN_C_

typedef struct {
	int weight;
    int parent;
    int left;
    int right;
} HuffmanTree;

typedef char *HuffmanCode;

void SelectNode(HuffmanTree *ht,int n,int *bt1,int *bt2);

void CreateTree(HuffmanTree *ht,int n,int *w);

void HuffmanCoding(HuffmanTree *ht,int n,HuffmanCode *hc);

void Encode(HuffmanCode *hc,char *alphabet,char *str,char *code);

void Decode(HuffmanTree *ht,int m,char *code,char *alphabet,char *decode);

void HuffmanTreeTest();

#endif /* HUFFMAN_C_ */
