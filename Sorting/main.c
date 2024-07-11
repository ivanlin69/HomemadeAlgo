#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"

int main(int argc, const char * argv[]) {
    
    int A[] = {8, 5, 7, 3, 2, 16, 13, 29};
    int B[] = {2, 3, 5, 7, 8, 13, 16, 29};
    int length = 8;
    
    BubbleSort(A, length);
    
    for(size_t i=0; i<length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
