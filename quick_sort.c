#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void swap(int *a, int *b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}
void quick_sort(int* arry, int left, int right)
{
	int l, r, temp;
	
	if (left > right)
	{
		return;
	}
	
	l = left;
	r = right;
	temp = arry[l];

	
	while (l < r)
	{
		while ((l < r) && (temp <= arry[r]))
		{
			r--;
		}
		while ((l < r) && (temp >= arry[l]))
		{
			l++;
		}

		if (l < r)
		{
			swap(&arry[l], &arry[r]);
		}
	}

	arry[left] = arry[l];
	arry[l] = temp;

	quick_sort(arry, left, l - 1);
	quick_sort(arry, l + 1, right);
	return;
}