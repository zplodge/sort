#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quick_sort(int* arry, int left, int right)
{
	int l, r, temp;

	l = left;
	r = right;
	temp = arry[l];

	if (l >= r)
	{
		return;
	}
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
			int value;
			value = arry[r];
			arry[r] = arry[l];
			arry[l] = value;
		}
	}

	arry[left] = arry[l];
	arry[l] = temp;

	quick_sort(arry, left, l - 1);
	quick_sort(arry, l + 1, right);
	return;
}