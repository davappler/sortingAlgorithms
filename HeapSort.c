#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

//void sort(int* A, size_t length);
void Build_Max_Heap(int* A, size_t length);
void Max_Heapify(int* A, size_t i, size_t length);
void HeapSort(int* A, size_t length);



void sort(int* A, size_t length)
{
	if(length<=0)
		return;

	if(!A)
	{
		printf("Pointer doesn't point to an address \n") ;
		exit(EXIT_FAILURE); 
	}

	HeapSort(A,(length-1));
	return;

}


void Build_Max_Heap(int* A, size_t length)
{
	if(length<=0)
		return;

	if(!A)
	{
		printf("Pointer in Build_Max_Heap doesn't point to an address \n") ;
		exit(EXIT_FAILURE); 
	}

	size_t k;
	if(length%2==0)         // We check if the  length of array is an even number .
		 k =(length/2) -1;  // If it the case then we set K to this value, otherwise another value 
		                    // after the value of k every element in the array is a leaf.
		                    // by leaf we mean to say that these elements will not become parents.
		                    // So no need to call Max_Heapify for these elements.
	else 
		 k=(length/2);

	for( int i=k ; i>=0 ; i-- )
		Max_Heapify(A,i,length);
	
	return;
}



void Max_Heapify(int* A, size_t i, size_t length)
{
	if(length<=0)
		return;

	if(!A)
	{
		printf("Pointer in Max_Heapify doesn't point to an address \n") ;
		exit(EXIT_FAILURE);
	}
	if(length%2==0 && i>= (length/2) )   // after length/2 elements are leaf.
	    return;                          // so they do not possede any Left and Right elements to be tested . 
		

	if(length%2!=0 && i>= ((length/2) + 1 ))  
		return;

	size_t L= 2*i +1 ;     // This is the index of left child 
	size_t R= 2*i +2 ;     // This is the index of right child.
	size_t largest=i ;

	 if(L<=length && A[L]>A[i])    // Here we compare the left child with parent.
	 	largest =L;

	 if(R<=length && A[R]>A[largest])  // Here we compare the right child with the largest among left child and parent.
	 	largest =R;

	 if(largest!=i)
	 {
	 	int temp;
	 	temp = A[i];
	 	A[i]=A[largest];
	 	A[largest]=temp;
	 }
	 else 
	 	return;

	 Max_Heapify(A,largest,length);

	  return;

}




void HeapSort(int* A, size_t length)
{
	if(length<=0)
		return;

	if(!A)
	{
		printf("Pointer in Max_Heapify doesn't point to an address \n") ;
		exit(EXIT_FAILURE);
	}



	Build_Max_Heap(A,length);

	for( size_t i=length ; i>0 ; i-- )
	{
		int temp;
	 	temp = A[i];
	 	A[i]=A[0];
	 	A[0]=temp;

	 	length-=1;
	 	Max_Heapify(A,0,length);

	}

return;

}







