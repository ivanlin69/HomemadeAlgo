#ifndef Hashing_h
#define Hashing_h

#define hashingSIZE 10

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/**
 # Hash collision techniques
 # Open hashing - Chainging
 # Close hashing - Linear probing, Quadratic probing
 */

/**
 # Open Hashing - Chainging
 # Here we use simple hashing function(%10) to simulate
 */
struct hashChaining{
    // an array of pointers to nodes
    struct LinkedList *hashing[hashingSIZE];
};

void InitializeHC(struct hashChaining *h){
    for(size_t i=0; i<hashingSIZE; i++){
        h->hashing[i] = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    }
}

int hashFunction(int value){
    return value % 10;
}

int InsertHC(struct hashChaining *h, int value){
    if(h == NULL){
        printf("Invalid hashing.\n");
        return -1;
    }
    InsertSorted(h->hashing[hashFunction(value)], value);
    return 0;
}

int SearchHC(struct hashChaining *h, int value){
    if(h == NULL){
        printf("Invalid hashing.\n");
        return -1;
    }
    struct Node *r = Search(h->hashing[hashFunction(value)], value);
    if(r != NULL){
        printf("Element found.\n");
        return r->value;
    }
    printf("Element not found.\n");
    return -1;
}

int DeleteHC(struct hashChaining *h, int value){
    if(h == NULL){
        printf("Invalid hashing.\n");
        return -1;
    }
    return Delete(h->hashing[hashFunction(value)], value);
}

void FreeHC(struct hashChaining *h){
    for(size_t i=0; i<hashingSIZE; i++){
        freeLinkedlist(h->hashing[i]);
    }
}





/**
 # Closed Hashing - Linear Probing
 # Note that the loading factor must be less than 0.5(number of elements/size of hashing)
 #  Then for searching it can be terminated gracefully with the 'space'
 #  This is also the drawback of linear probing, half spaces is wasted and time comsuming(due to clusters), also it's exhausting for deleting an element since we need to check the post elements and see if they needed to be shifted(normally is solved by rehashing all elements), and that's the reason why it's commonly not encouraged to delete an element if you use linear probing
 */
struct hashLinearProb{
    // an array of pointers to nodes
    int *hashing;
};

void InitializeHLP(struct hashLinearProb *h){
    h->hashing = (int *) malloc(sizeof(int)*hashingSIZE);
    for(size_t i=0; i<hashingSIZE; i++){
        h->hashing[i] = -1;
    }
}

int InsertHLP(struct hashLinearProb *h, int value){
    if(h == NULL){
        printf("Invalid hashing.\n");
        return -1;
    }
    
    int index = hashFunction(value);
    int i = 1;
    while(h->hashing[index] != -1 && i<hashingSIZE){
        index = (value + i) % hashingSIZE;
        i++;
    }
    h->hashing[index] = value;
    return 0;
}

int SearchHLP(struct hashLinearProb *h, int value){
    if(h == NULL){
        printf("Invalid hashing.\n");
        return -1;
    }
    int index = hashFunction(value);
    int r = h->hashing[index];
    while(r != -1){
        if(r == value){
            printf("Element found.\n");
            return r;
        }
        index++;
        r = h->hashing[index];
    }
    printf("Element not found.\n");
    return -1;
}

void FreeHLP(struct hashLinearProb *h){
    free(h->hashing);
}


#endif /* Hashing_h */
