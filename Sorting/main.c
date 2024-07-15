#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"

int main(int argc, const char * argv[]) {
    
    int A[] = {8, 5, 16, 3, 2, 16, 13, 29};
    int B[] = {3, 5, 7, 8, 13, 16, 16, 29};
    int C[] = {2, 2, 1, 2, 2, 1, 2, 2};
    int D[] = {17, 18, 26, 29};
    int E[] = {3, 5, 8, 16, 2, 13, 16, 29};
    int lengthA = 8;
    int lengthD = 4;
    
    //BubbleSort(A, length);
    //InsertionSort(A, length);
    //SelectionSort(A, length);
    //QuickSort(A, 0, lengthA-1);
    //MergeSortR(A, 0, lengthA-1);
    
    /*
    int * Merge = Merge2Sorted(B, D, lengthA, lengthD);
    printf("Test for merge: \n");
    for(size_t i=0; i<lengthA+lengthD; i++){
        printf("%d ", Merge[i]);
    }
    printf("\n");
    
    int * MergeSingle = Merge2SortedSingle(E, 0, (lengthA-1)/2, lengthA-1);
    printf("Test for mergeSingle: \n");
    for(size_t i=0; i<lengthA; i++){
        printf("%d ", MergeSingle[i]);
    }
    printf("\n");
    
    printf("Test for MergeSort: \n");
    for(size_t i=0; i<lengthA; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    */
    
    //CountSort(A, lengthA);
    ShellSort(A, lengthA);
    
    for(size_t i=0; i<lengthA; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    

    return 0;
}
