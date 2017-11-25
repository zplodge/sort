#include <stdio.h>
#include <stdlib.h>
//#include "sort.h"


int  main(void)
{
	int i=0;
	//int arry[MAX_SIZE] = {0};
	int arry[10] = {9,6,3,7,2,5,0,1,4,8};
	//for (i = 0; i < MAX_SIZE; i++)
	{
	//	arry[i] = rand();//randomize();//rand();
	}
	//quick_sort(arry, 0, MAX_SIZE-1);
	quick_sort(arry, 0, 10);
	printf("quick sort ok\n\r");
	
	for(i=0; i<10; i++)
	{
		printf(" %d ", arry[i]);
	}
	printf("\n\r");
	
	return 1;
}



