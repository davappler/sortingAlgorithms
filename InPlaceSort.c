#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"


//void sort(int* array, size_t length);
void InMerge(int* array, size_t a, size_t b);
void InPlaceMerge(int* array,size_t p,size_t q,size_t r);


void sort(int* array, size_t length)
{
	if(length<=0)
		return;

	if(!array)
	{
		printf("Pointer doesn't point to an address \n") ;
		exit(EXIT_FAILURE);
	}
	InMerge(array,0,(length-1));
	return;
}




void InMerge(int* array, size_t a, size_t b)  // a is for beginning 
{                                             // b is for end.
    if(!array)
	{
		printf("Pointer doesn't point to an address \n") ;
		exit(EXIT_FAILURE);
	}
    if(a<b)
    {
        size_t mid= (a+b)/2; 
        InMerge(array,a,mid);         
        InMerge(array,(mid+1),b);
        InPlaceMerge(array,a,mid,b);
    }
    return;
}



void InPlaceMerge(int* array,size_t p,size_t q,size_t r)
{

	if(!array)
	{
		printf("Pointer doesn't point to an address \n") ;
		exit(EXIT_FAILURE); 
	}
	size_t i=p ;
	size_t j=q+1 ;

	while(i<=q && j<=r)
	{
		if(array[i]<=array[j])    // If the element of left subarray is smaller than Right subarray 
			i++;                  // then we simply increment i.
			
		else
		{
			int temp =array[j];

			for(size_t k=j;k>i;k--)  // Here we move the left subarray one place to the right.
				array[k]=array[k-1]; 

			array[i]=temp;
			i++;
			j++;
			q++;
			
		}
	}

}

