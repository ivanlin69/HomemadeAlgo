#include <stdio.h>
#include "Hashing.h"

int main(int argc, const char * argv[]) {
    
    printf("Chaining:\n");
    struct hashChaining hc;
    InitializeHC(&hc);
    int A[] = {3, 8, 5, 4, 19, 13};
    int lengthA = 6;
    
    for(size_t i=0; i<lengthA; i++){
        InsertHC(&hc, A[i]);
    }
    
    printf("Search for 3: %d  \n", SearchHC(&hc, 3));
    printf("Delete for 13: %d  \n", DeleteHC(&hc, 13));
    
    FreeHC(&hc);
    
    printf("LinearProb:\n");
    struct hashLinearProb hlp;
    InitializeHLP(&hlp);
    int B[] = {12, 25, 35, 36};
    int lengthB = 4;
    
    for(size_t i=0; i<lengthB; i++){
        InsertHLP(&hlp, B[i]);
    }
    
    printf("Search for 35: %d  \n", SearchHLP(&hlp, 35));
    
    FreeHLP(&hlp);

    printf("QuadProb:\n");
    struct hashQuadProb hqp;
    InitializeHQP(&hqp);
    int C[] = {13, 23, 43, 37};
    int lengthC = 4;
    
    for(size_t i=0; i<lengthC; i++){
        InsertHQP(&hqp, C[i]);
    }
    printf("Search for 23: %d  \n", SearchHQP(&hqp, 23));
    
    FreeHQP(&hqp);
    return 0;
}
