#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#define  MAX_SIZE  0xffff

typedef enum
{
	QUICK_SORT,
	HEAP_SORT,
	MERGE_SORT
}SORT_T;

void quick_sort(int* arry, int left, int right);
void heap_sort(int* arry, int len);
void merge_sort(int* arry, int left, int right);


#endif