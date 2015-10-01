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
    position currentPos;
    int collisionNum;

    collisionNum = 0;
    currentPos = hash(X,H->tableSize);
    while (H->theCells[currentPos].info != empty && H->theCells[currentPos].content != X){
        currentPos += 2 * ++collisionNum -1;
        if(currentPos >= H->tableSize)
            currentPos -= H->tableSize;
    }
    return currentPos;
}

void insert(elementType X, hashTable H){

}

hashTable rehash(hashTable H){

}