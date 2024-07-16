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
    
    return 0;
}
