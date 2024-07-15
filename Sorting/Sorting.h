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
 # (An adaptive sorting algorithm is one that has better performance when the input data is already partially sorted or sorted.)
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


/**
 # (max) of comparison: n^2
 # (max) of swap: n(only swap if condition is met for each pass), which is the only sorting algo that requires O(n) swaps
 # Extra memories are not required
 # Time: min=max: O(n^2) for the worst case
 # It's not stable(the order of duplicates can be changed)
 # It's not adaptive, it must iterate through the unsorted portion to find the local minimum
 # Like Bubble sort, it provides useful information(k passes, k sorted elements)
*/
void SelectionSort(int *A, int n){
    size_t i, j, k = 0;
    for(i=0; i<n-1; i++){
        k = i;
        for(j=i+1; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        
        if(k != i){
            Swap(&A[k], &A[i]);
        }

    }
}

/**
 # Idea: If all the elements before the element ara smaller, and all the elements after the element are bigger, then the element is sorted.
 # (max) of comparison: O(nlog(n))
 # (max) of swap: n(only swap if condition is met for each pass), which is the only sorting algo that requires O(n) swaps
 # Extra memories are not required
 # Time: min: O(nlog(n)), if pivot is middle element(after sorted), which means it's a perfect partition; max: O(n^2) for the worst case if the leftmost or rightmost element is chosen as pivot. the average time is: O(nlog(n))
 # It's not stable
 # It's not adaptive
 # Partitioning swaps elements across the pivot, disrupting the relative order of equal elements, so it's not stable. To make it stable, we would need additional space or more complex partitioning scheme that preserves order, which is not typically done because it sacrifices the in-place nature and simplicity of QuickSort.
 
 # This is the case that we choose first element as pivot. Now if we choose middle element as pivot, then the best case and the worst case will be reversed.
*/
void QuickSort(int *A, int l, int r){
    
    if(l >= r){
        return;
    }
    /**
     # If we want to change the candidate of pivot, like middle:
        int mid = l + (r-l)/2; // prevent overflow
      Swap(&A[mid], &A[l]);  // Move the pivot to the front
     
     # Or we can randomly choose pivot everytime, that will be randomized Quick sort
     */
    int pivot = A[l];
    int i = l + 1;
    int j = r;
    
    while(1){
        // make sure all the range is covered, A[i] <= pivot and A[j] > pivot
        while(A[i] <= pivot && i <= r){
            i++;
        }
        while(A[j] > pivot && j >= l){
            j--;
        }
        if(i > j){
            break;
        }
        Swap(&A[i], &A[j]);
        i++;
        j--;
    }
    Swap(&A[j], &A[l]);
    QuickSort(A, l, j-1);
    QuickSort(A, j+1, r);
}

int * Merge2Sorted(int *A, int *B, size_t m, size_t n){
    
    int * C = (int *) malloc(sizeof(int)*(m+n));
    size_t i=0, j=0, k=0;
    
    while(i<m && j<n){
        if(A[i] < B[j]){
            C[k++] = A[i++];
        } else if(A[i] > B[j]){
            C[k++] = B[j++];
        } else{
            C[k++] = A[i++];
            C[k++] = B[j++];
        }
    }
    while(i<m){
        C[k++] = A[i++];
    }
    while(j<n){
        C[k++] = B[j++];
    }
    return C;
}

// In comparison based sorting, merge sort is the only algorithm requires extra spaces
int * Merge2SortedSingle(int *A, size_t low, size_t mid, size_t high){
    
    int * B = (int *) malloc(sizeof(int)*(high-low+1));
    size_t i=low, j=mid+1, k=0;
    
    while(i<mid+1 && j<high+1){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        } else if(A[i] > A[j]){
            B[k++] = A[j++];
        } else{
            B[k++] = A[i++];
            B[k++] = A[j++];
        }
    }
    while(i<mid+1){
        B[k++] = A[i++];
    }
    while(j<high+1){
        B[k++] = A[j++];
    }
    for(size_t index=low, k=0; index<high+1; index++, k++){
        A[index] = B[k];
    }
    free(B);
    return A;
}

void MergeSort(int *A, size_t n){
    size_t i=0, p=0, low=0, mid=0, high=0;
    // Gap between elements, can up to n
    for(p=2; p<n+1; p*=2){
        for(i=0; i<n-1; i+=p){
            low = i;
            high = i+(p-1);
            mid = low + (high-low)/2;
            Merge2SortedSingle(A, low, mid, high);
        }
    }
    if(high < n-1){
        Merge2SortedSingle(A, 0, high, n-1);
    }
}

/**
 # Idea: 2-way sorting(merge 2 sorted list, and a list with single element is sorted).
 # (max) of comparison: O(nlog(n))
 # NO swap
 # Extra memories are required
 # Time: min: O(nlog(n)), if pivot is middle element(after sorted), which means it's a perfect partition; max: O(n^2) for the worst case if the leftmost or rightmost element is chosen as pivot. the average time is: O(nlog(n))
 # It's stable
 # It's not adaptive
*/
void MergeSortR(int *A, size_t low, size_t high){
    
    if(low >= high){
        return;
    }
    // post order
    size_t mid = low + (high - low)/2;
    MergeSortR(A, low, mid);
    MergeSortR(A, mid+1, high);
    Merge2SortedSingle(A, low, mid, high);
}

/**
 # Idea: Take the advantage of indices
 # Normally is only used with non-negative integers
 # Can handle duplicates also since it stores the count of the element
 # Not comparison based algorithm
 # NO swap
 # It requires significant memories if the maximum element is big
 # Time: O(n)
 # It's stable
 # It's not adaptive
*/
void CountSort(int *A, size_t n){
    
    int max = A[0];
    for(size_t i=0; i<n; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    int *hashing = (int *) calloc(max+1, sizeof(int));
    for(size_t i=0; i<n; i++){
        hashing[A[i]] += 1;
    }
    size_t j=0;
    for(int i=0; i<max+1; i++){
        while(hashing[i] > 0){
            A[j++] = i;
            hashing[i]--;
        }
    }
    free(hashing);
}

/**
 # Idea: Take the concept of insertion sort
 # The time complexity is related to the selection of GAP
 # Since it uses idea of insertion sort, it's a comparison based algorithm
 # No extra memories is needed
 # Time: less than O(n^2), for this case, is O(nlog(n)) if we see each pass as just n
 #  If using primary number with gap then it can be like O(n^3/2) or O(n^5/3)
 # It's not stable, large-gap exchanges can disrupt the relative order of duplicates
 # It's adaptive. Given a sorted array can improve its efficency
*/
void ShellSort(int *A, size_t n){
    int gap = (int) n/2;
    
    while(gap >= 1){
        int p1=0, p2=0;
        for(int i=0; i<n && p2<n; i++){
            p1 = i;
            p2 = i+gap;
            
            while(p1 >= 0 && A[p1] > A[p2]){
                Swap(&A[p1], &A[p2]);
                p2 = p1;
                p1 = p1-gap;
            }
        }
        gap = gap/2;
    }
}


#endif /* Sorting_h */
