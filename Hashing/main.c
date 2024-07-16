#include <stdio.h>
#include "Hashing.h"

int main(int argc, const char * argv[]) {
    
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
    
    
    struct hashLinearProb hlp;
    InitializeHLP(&hlp);
    int B[] = {12, 25, 35, 36};
    int lengthB = 4;
    
    for(size_t i=0; i<lengthB; i++){
        InsertHLP(&hlp, B[i]);
    }
    
    printf("Search for 35: %d  \n", SearchHLP(&hlp, 35));
    //printf("Delete for 13: %d  \n", DeleteHLP(&hlp, 13));
    
    FreeHLP(&hlp);
    
    return 0;
}
