/**
 * hashQuad.h : 
 * @author      Ethan
 * @date        2015/9/18 20:47
 * @description :
 */


#ifndef PRACTICE_HASHQUAD_H
#define PRACTICE_HASHQUAD_H

#include <stdio.h>
#include <stdlib.h>
#include "../lib/createPrime.h"

typedef unsigned int index;
typedef index position;

struct hashTal;
typedef struct hashTal *hashTable;

typedef int elementType;

hashTable initTable(int tableSize);
void destoryTable(hashTable H);
position find(elementType X, hashTable H);
void insert(elementType X, hashTable H);
hashTable rehash(hashTable H);
int hash(int key,int tableSize);

#endif //PRACTICE_HASHQUAD_H

enum kindOfEntry {legitimate, empty, deleted};

struct hashEntry{
    elementType content;
    enum kindOfEntry info;
};

typedef struct hashEntry cell;
struct hashTal{
    int tableSize;
    cell *theCells;
};