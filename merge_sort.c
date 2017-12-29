#include <stdio.h>
#include <stdlib.h>

//static int  test_arry[] = { 5, 7, 1, 4, 8, 3, 9, 2, 6, 0 };

static void merge_arry(int *arry, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;
	int len = right - left + 1;
	int *temp = NULL;

	if (NULL == (temp = malloc(sizeof(int)*len)))
	{
		return;
	}
	while (i <= mid && j <= right)
	{
		if (arry[i] <= arry[j])
		{
			temp[k++] = arry[i++];
		}
		else
		{
			temp[k++] = arry[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = arry[i++];
	}

	while (j <= right)
	{
		temp[k++] = arry[j++];
	}

	for (k = 0, i = left; i <= right; i++, k++)
	{
		arry[i] = temp[k];
	}
	free(temp);
}

void merge_sort(int* arry, int left, int right)
{

	if (arry == NULL)
	{
		return;
	}
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(arry, left, mid);
		merge_sort(arry, mid + 1, right);
		merge_arry(arry, left, mid, right);
	}
	return;
}
