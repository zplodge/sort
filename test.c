#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "sort.h"

#define MAX_NUM   1000001
#define MAX_RAND  10


int get_time(struct timeval *time)
{
	if(NULL == time)
	{
		return 0;
	}
	gettimeofday(time, NULL);
	
	return 1;
}

int  main(void)
{
	int i=0, j=0;
	int *arry = NULL;
	struct timeval start_time, end_time;
	struct timeval tp;
	
	int quick_sort_time = 0;
	
	memset(&start_time, 0, sizeof(struct timeval));
	memset(&end_time, 0, sizeof(struct timeval));
	
	if(NULL == (arry = malloc(sizeof(int)*MAX_NUM)))
	{
		return 0;
	}
	
	while(j < MAX_RAND)
	{
		i = 0;
		gettimeofday(&tp , NULL);
		srand(tp.tv_usec);
		while(i < MAX_NUM)
		{
			arry[i++] = (1 + (int)(100000000.0*rand()/(RAND_MAX+1.0)));
		}
		
		get_time(&start_time);
		quick_sort(arry, 0, MAX_NUM-1);
		get_time(&end_time);
		quick_sort_time = (end_time.tv_sec - start_time.tv_sec)*1000000 + end_time.tv_usec - start_time.tv_usec;
		printf("quick sort time:%d us \n\r", quick_sort_time);
		j++;
	}

	free(arry);
	
	return 1;
}



