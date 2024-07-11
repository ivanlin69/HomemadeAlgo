#ifndef Sorting_h
#define Sorting_h

#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// # of comparison = n^2
// # (max) of swap = n^2
// extra memories are not required
void BubbleSort(int *A, int n){
    int count = 0;
    int sorted = 1;  // for adaptivity
    // # of passes is n-1
    while(count < n){
        sorted = 1;
        // n-1-count, after each pass an element is sorted, no comparison needed
        for(size_t i=0; i<n-1-count; i++){
            if(A[i] > A[i+1]){
                Swap(&A[i], &A[i+1]);
                sorted = 0;
            }
        }
        if(sorted){
            break;
        }
        count++;
    }
}

#endif /* Sorting_h */
