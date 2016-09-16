/*
 ============================================================================
 Name        : huffman.c
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : huffman c source file
 ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "huffman.h"

void SelectNode(HuffmanTree *ht,int n,int *bt1,int *bt2) {
	int i;
	HuffmanTree *ht1, *ht2, *t;
	ht1 = ht2 = NULL;
	for (i=1; i<=n; i++) {
		if (!ht[i].parent) {
			if (ht1 == NULL) {
				ht1 = ht + i;
			}
			if (ht2 == NULL) {
				ht2 = ht + i;
				if (ht1->weight > ht2->weight) {
					t = ht2;
					ht2 = ht1;
					ht1 = t;
				}
				continue;
			}
			if (ht1 && ht2) {
				if (ht[i].weight <= ht1->weight) {
					ht2 = ht1;
					ht1 = ht + i;
				} else if (ht[i].weight < ht2->weight) {
					ht2 = ht + i;
				}
			}
		}
	}

	if(ht1>ht2){
		*bt2=ht1-ht;
		*bt1=ht2-ht;
	}else{
		*bt1=ht1-ht;
		*bt2=ht2-ht;
	}
}

void CreateTree(HuffmanTree *ht,int n,int *w) {
	int i,m=2*n-1;
	int bt1,bt2;
	if(n<=1)
		return ;

	for(i=1;i<=n;++i) {
		ht[i].weight = w[i-1];
		ht[i].parent = 0;
		ht[i].left = 0;
		ht[i].right = 0;
	}

	for(;i<=m;++i) {
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].left = 0;
		ht[i].right = 0;
	}

	for(i=n+1;i<=m;++i) {
		SelectNode(ht,i-1,&bt1,&bt2);
		ht[bt1].parent = i;
		ht[bt2].parent = i;
		ht[i].left = bt1;
		ht[i].right = bt2;
		ht[i].weight = ht[bt1].weight+ht[bt2].weight;
	}
}

void HuffmanCoding(HuffmanTree *ht,int n,HuffmanCode *hc) {
	char *cd;
	int start,i;
	int current,parent;
	cd=(char*)malloc(sizeof(char)*n);
	cd[n-1]='\0';

	for(i=1;i<=n;i++) {
		start=n-1;
		current=i;
		parent=ht[current].parent;
		while(parent)
		{
			if(current==ht[parent].left)
				cd[--start]='0';
			else
			    cd[--start]='1';
			current=parent;
			parent=ht[parent].parent;
		}
		hc[i-1]=(char*)malloc(sizeof(char)*(n-start));
		strcpy(hc[i-1],&cd[start]);
	}
	free(cd);
}

void Encode(HuffmanCode *hc,char *alphabet,char *str,char *code) {
	int len=0,i=0,j;
	code[0]='\0';
	while(str[i]) {
		j=0;
		while(alphabet[j]!=str[i])
			j++;
		strcpy(code+len,hc[j]);
		len=len+strlen(hc[j]);
		i++;
	}
	code[len]='\0';
}

void Decode(HuffmanTree *ht,int m,char *code,char *alphabet,char *decode) {
	int position=0,i,j=0;
	m=2*m-1;
	while(code[position]) {
		for(i=m;ht[i].left && ht[i].right; position++) {
			if(code[position]=='0')
				i=ht[i].left;
			else
				i=ht[i].right;
		}
		decode[j]=alphabet[i-1];
		j++;
	}
	decode[j]='\0';
}

void HuffmanTreeTest() {
	int i,n=4,m;
	char test[]="DBDBDABDCDADBDADBDADACDBDBD";
	char code[100],code1[100];
	char alphabet[]={'A','B','C','D'};
	int w[]={5,7,2,13} ;
	HuffmanTree *ht;
	HuffmanCode *hc;
	m=2*n-1;

	ht=(HuffmanTree *)malloc((m+1)*sizeof(HuffmanTree));
	if(!ht)  {
		printf("内存分配失败！\n");
		exit(0);
	}

	hc=(HuffmanCode *)malloc(n*sizeof(char*));
	if(!hc) {
		printf("内存分配失败！\n");
		exit(0);
	}

	CreateTree(ht,n,w);
	HuffmanCoding(ht,n,hc);
	for(i=1;i<=n;i++)
		printf("字母:%c,权重:%d,编码为 %s\n",alphabet[i-1],ht[i].weight,hc[i-1]);

	Encode(hc,alphabet,test,code);
	printf("\n字符串:\n%s\n转换后为:\n%s\n",test,code);

	Decode(ht,n,code,alphabet,code1);
	printf("\n编码:\n%s\n转换后为:\n%s\n",code,code1);
}


