#include <stdio.h>
#include <stdlib.h>

//int  test_arry[] = { 5, 7, 1, 4, 8, 3, 9, 2, 6 , 0};

static void swap(int *a, int *b)
{
	if(a == b)
	{
		return;
	}
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

static void heap_adjust(int *arry, int parent, int len)
{
	int left, right;
	int current_parent = arry[parent];
	int index = 0;

	left = parent * 2 + 1;
	right = parent * 2 + 2;

	if (left > len)
	{
		return;
	}

	if (arry[left]<arry[right] && right <= len)
	{
		if (arry[parent] < arry[right])
		{
			index = right;
			arry[parent] = arry[right];
		}
		else
		{
			return;
		}
	}
	else
	{
		if (arry[parent] < arry[left])
		{
			index = left;
			arry[parent] = arry[left];
		}
		else
		{
			return;
		}
	}
	arry[index] = current_parent;
	heap_adjust(arry, index, len);
}

void heap_sort(int* arry, int len)
{
	int i;

	for (i = (len - 1) / 2; i>=0; i--)
	{
		heap_adjust(arry, i, len - 1);
	}

	swap(&arry[0], &arry[len - 1]);
	
	for (i = len - 2; i >= 0; i--)
	{
		heap_adjust(arry, 0, i);
		if (i > 0)
		{
			swap(&arry[0], &arry[i]);
		}
	}
	return;
}
