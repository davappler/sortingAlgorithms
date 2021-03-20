#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

//void sort(int* array, size_t length);
void QuickSort(int* array, size_t a, size_t b);
int partition(int* array, size_t a, size_t b);


void sort(int* array, size_t length)
{
	if(length<=0)
		return;
	if(!array)
	{
		printf("Pointer doesn't point to an address \n") ;
		exit(EXIT_FAILURE); 
	}
	
	QuickSort(array,0,(length-1));
	return;

}



void QuickSort(int* array, size_t a, size_t b)
{
	if(!array)
	{
		printf("Pointer doesn't point to an address \n") ;
		exit(EXIT_FAILURE); 
	}

	int q;
	if(a<b)
	{
		q=partition(array,a,b);

		// -------- before calling the function we check if index is not negative.--------.
		if(q>0)
			QuickSort(array,a,q-1); 

		QuickSort(array,q+1,b);
	}
	return;
}

int partition(int* array, size_t a, size_t b)
{
	if(!array)
	{
		printf("Pointer doesn't point to an address \n") ;
		exit(EXIT_FAILURE); 
	}
	size_t i=a-1;
	size_t temp;

	for(size_t j=a;j<b;j++)
	{
		if(array[j]<=array[b])
		{
			i+=1;
			temp = array[j];
			array[j]=array[i] ;
			array[i]=temp;
		}
	}
	
    temp=array[b];
    array[b]=array[i+1];
    array[i+1]=temp;

	return i+1;
}


