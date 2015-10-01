/**
 * hashQuad.c : 
 * @author      Ethan
 * @date        2015/9/18 20:47
 * @description :
 */

#include "hashQuad.h"

hashTable initTable(int tableSize){
    hashTable H;
    int i;

    if(tableSize < 10){
        printf("Table size too small");
        return NULL;
    }
    H = malloc(sizeof(struct hashTal));
    if( H == NULL ){
        printf("Out of space!");
        return NULL;
    }

    H->tableSize = getCloseinLargerNum(tableSize);

    H->theCells = malloc(sizeof(cell) * H->tableSize);
    if(H->theCells == NULL){
        printf("Out of space!");
        return NULL;
    }

    for(i = 0; i < H->tableSize; ++i){
        H->theCells[i].info = empty;
    }
    return H;
}

void destoryTable(hashTable H){

}

position find(elementType X, hashTable H){

}

void insert(elementType X, hashTable H){

}

hashTable rehash(hashTable H){

}