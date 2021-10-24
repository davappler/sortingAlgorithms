#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Array.h"
#include "Sort.h"

static const size_t ARRAY_LENGTH = 10000;

/* Prototypes */

/* ------------------------------------------------------------------------- *
 * Compute the CPU time (in seconds) used by the Sort function.
 *
 * PARAMETERS
 * array        Array to sort
 * length       Number of elements in the array
 *
 * RETURN
 * seconds      The number of seconds used by Sort
 * ------------------------------------------------------------------------- */
static double cpuTimeUsedToSort(int* array, size_t length)
{
    clock_t start = clock();
    sort(array, length);
    //MergeSort(array, 0, length);
   //InMerge(array, 0, length);
    //QuickSort(array,0,length);
    //HeapSort(array,length);

    return ((double) (clock() - start)) / CLOCKS_PER_SEC;
}



/* ------------------------------------------------------------------------- *
 * Main
 * ------------------------------------------------------------------------- */
int main(void)
{
    srand(time(NULL));//Use an integer seed to get a fix sequence

    printf("Sorting times for arrays of size %zu\n", ARRAY_LENGTH);
    printf("-----------------------------\n");
    printf("Array type | Sorting time [s]\n");
    printf("-----------------------------\n");

    // ---------------------------- Sorted array ---------------------------- //
    int* sorted = createSortedArray(ARRAY_LENGTH);
    if (!sorted)
    {
        fprintf(stderr, "Could not created sorted array. Aborting...\n");
        return EXIT_FAILURE;
    }

    double sec = cpuTimeUsedToSort(sorted, ARRAY_LENGTH);
    printf("Sorted     | %f\n", sec);
    free(sorted);

    // -------------------------- Decreasing array -------------------------- //
    int* decreasing = createDecreasingArray(ARRAY_LENGTH);
    if (!decreasing)
    {
        fprintf(stderr, "Could not created decreasing array. Aborting...\n");
        return EXIT_FAILURE;
    }

    sec = cpuTimeUsedToSort(decreasing, ARRAY_LENGTH);
    printf("Decreasing | %f\n", sec);
    free(decreasing);

    // ---------------------------- Random array ---------------------------- //
    int* random = createRandomArray(ARRAY_LENGTH);
    if (!random)
    {
        fprintf(stderr, "Could not created random array. Aborting...\n");
        return EXIT_FAILURE;
    }

    sec = cpuTimeUsedToSort(random, ARRAY_LENGTH);
    printf("Random     | %f\n", sec);
    free(random);

    printf("-----------------------------\n");

    return EXIT_SUCCESS;
}
