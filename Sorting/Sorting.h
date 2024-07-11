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
void BubbleSort(int *A, int n){
    int count = 0;
    int sorted = 1;  // for adaptivity
    while(count < n){
        sorted = 1;
        for(size_t i=0; i<n-1; i++){
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
