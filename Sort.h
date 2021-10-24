/* ========================================================================= *
 * Sort
 * ========================================================================= */

#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
 * Sort an array of integers.
 *
 * PARAMETERS
 * array        The array to sort
 * length       Number of elements in the array
 * ------------------------------------------------------------------------- */
void sort(int* array, size_t length);

void MergeSort(int* array, size_t a, size_t b);
void Merge(int* array, size_t a, size_t mid ,size_t b);

int  partition(int* array, size_t a, size_t b);
void QuickSort(int* array, size_t a, size_t b);

void Build_Max_Heap(int* A, size_t length);
void Max_Heapify(int* A, size_t i, size_t heap_size);
void HeapSort(int* A, size_t length);

void InMerge(int* array, size_t a, size_t b);
void InPlaceMerge(int* array,size_t p,size_t q,size_t r);


#endif // !_SORT_H_
