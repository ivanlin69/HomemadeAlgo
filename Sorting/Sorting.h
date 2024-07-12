#ifndef Sorting_h
#define Sorting_h

#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 # (max) of comparison: n^2
 # (max) of swap: n^2
 # Extra memories are not required
 # Time: min: O(n) if sorted, max: O(n^2) for the worst case
 # It's stable(order of duplicates are not changed)
 # It's not adaptive without using flag; otherwise it's adaptive
*/
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

/**
 # (max) of comparison: n^2
 # (max) of swap: n^2
 # Extra memories are not required
 # Time: min: O(n) if sorted, max: O(n^2) for the worst case
 # It's stable(order of duplicates are not changed)
 # It's not adaptive if use nested for loops; but it's adaptive if use while loop to replace the inner loop
 # Unlike Bubble sort which gives informative results during the process(max/min elements), insertion sort does not. It must execute till the end we can ensure the array is sorted
 # Implemented with array shifting elements are required, but with linked list aren't(more suitable)
 # Only Bubble sort anf insertion sort are adaptive in most sorting algorithms
*/
void InsertionSort(int *A, int n){
    
    if(n == 1){
        return;
    }
    
    // for each element(except for the first), compare it with the sorted portion
    for(size_t i=1; i<n; i++){
        size_t j=i;
        // don't use another for loop, use while so it can terminate without compare all elements
        // in the sorted portion, and thus it's adaptive
        while(j>0 && A[j] < A[j-1]){
            Swap(&A[j], &A[j-1]);
            j--;
        }
    }
}


#endif /* Sorting_h */
