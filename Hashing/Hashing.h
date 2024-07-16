#ifndef Hashing_h
#define Hashing_h

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/**
 # Open Hasing - Chainging
 # Here we use simple hashing function(%10) to simulate
 */
struct hashChaining{
    // an array of pointers to nodes
    struct LinkedList *hashing[10];
};

void InitializeHC(struct hashChaining *h){
    for(size_t i=0; i<10; i++){
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
    for(size_t i=0; i<10; i++){
        freeLinkedlist(h->hashing[i]);
    }
}



#endif /* Hashing_h */
