/*
 ============================================================================
 Name        : index_search.h
 Author      : Yao
 Version     :
 Copyright   : Your copyright notice
 Description : index_search header file
 ============================================================================
 */

#ifndef INDEX_SEARCH_H_
#define INDEX_SEARCH_H_

#define INDEXTABLE_LEN 3
#define INDEX_TABLE_LEN 30

typedef struct item {
    int index;
    int start;
    int length;
} INDEXITEM;

long stu[INDEX_TABLE_LEN] = {
     1080101,1080102,1080103,1080104,1080105,1080106,0,0,0,0,
     1080201,1080202,1080203,1080204,0,0,0,0,0,0,
     1080301,1080302,1080303,1080304,0,0,0,0,0,0};

INDEXITEM indextable[INDEXTABLE_LEN] = {
	{10801,0,6},
    {10802,10,4},
    {10803,20,4}
};

int IndexSearch(int key);

void IndexSearchTest();

#endif /* INDEX_SEARCH_H_ */
