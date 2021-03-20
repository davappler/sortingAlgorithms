/* ========================================================================= *
 * MergeSort
 * Implementation of the InsertionSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

//void sort(int* array, size_t length);
void MergeSort(int* array, size_t a, size_t b);
void Merge(int* array, size_t a, size_t mid ,size_t b);


void sort(int* array, size_t length)
{
    if(length<=0)
        return;

    if(!array)
    {
        printf("Pointer doesn't point to an address \n") ;
        exit(EXIT_FAILURE);
    }
    MergeSort(array,0,(length-1));
    return;
}

void MergeSort(int* array, size_t a, size_t b)  // a is for beginning 
{                                               // b is for end.
    if(!array)
    {
        printf("Pointer doesn't point to an address \n") ;
        exit(EXIT_FAILURE); 
    }

    if(a<b)
    {
        size_t mid= (a+b)/2;
        MergeSort(array,a,mid);
        MergeSort(array,(mid+1),b);
        Merge(array,a,mid,b);
    }
    return;
}



void Merge(int* array, size_t a, size_t mid ,size_t b)
{
    if(!array)
    {
        printf("Pointer doesn't point to an address \n") ;
        exit(EXIT_FAILURE); 
    }
    size_t i,j;
    size_t n1 = mid-a+1; // n1 = mid-a+1; 
    size_t n2 = b-mid;
 
  
    int* L=(int*)malloc(n1*sizeof(int)); // Creating 2 new arrays for copying two sub tables.
    int* R=(int*)malloc(n2*sizeof(int));

    for(i=0; i<n1 ;i++)
        L[i]=array[a+i];

    for(j=0; j<n2; j++)
        R[j]=array[mid+1+j];

    i=0;
    j=0;
    for(size_t k=a; k<=b; k++)
    {
        
        if(i<n1 && j<n2)
        {
         
             if(L[i]<=R[j]) // here we compare which element is small between two sub arrays.
             {
                array[k]=L[i];

                if(n1==1 && n2==1)
                   array[k+1]=R[j];

                i+=1;
                
             }
             else
             {
                 array[k]=R[j];

                 if(n1==1 && n2==1)
                     array[k+1]=L[i];
                 
                 j+=1;
             }
        }
        else if(i<n1 && j>=n2) // here we check if we have reached last element of any one of the array 
                               // if it the case then we simply copy the other array to the original one.
        {
             array[k]=L[i];
                  i+=1;
        }

        else if(i>=n1 && j<n2)
        {
            array[k]=R[j];
                 j+=1;
        }        
       
    }
    
    free(L);  //  Here we will free the arrays.
    free(R);  //  which were dynamically allocated to perform fusion of two subarrays into a single array.
    
    return;

}


