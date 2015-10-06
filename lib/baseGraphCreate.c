/*
 * baseGraphCreate.c : 产生随机图
 * author     : ethan
 * createTime : 15/10/2 下午3:32
 * description:
 */

#include "baseGraphCreate.h"

/************ HASH TABLE START ************/
struct listNode{
    int vNum;
    char * content;
    position next;
};
struct hashTbl{
    int tableSize;
    list *theList;  //此处指针的指针是为形成一个数组
};

//散列函数
unsigned int hash(char * content, int tableSize){
    unsigned int hashVal = 0;
    while (content != '\0'){
        hashVal = (hashVal << 5) + *content++;
        return hashVal%tableSize;
    }
}

hashTable initHashTable(int tableSize){
    hashTable H;
    int i;
    H = malloc(sizeof(struct hashTbl));
    if(H == NULL){
        printf("Out of space!\n");
        return NULL;
    }
    H->tableSize = getCloseinLargerNum(tableSize);

    H->theList = malloc(sizeof(list) * H->tableSize);
    if(H->theList == NULL){
        printf("Out of space!\n");
        return NULL;
    }

    for (int i = 0; i < H->tableSize; ++i) {
        H->theList[i] = malloc(sizeof(struct listNode));
        if(H->theList[i] == NULL){
            printf("Out of space!\n");
            return NULL;
        }else{
            H->theList[i]->next = NULL;
        }
    }
    return H;
}

position find(char * content, hashTable H){
    position P;
    list L;
    L = H->theList[hash(content,H->tableSize)];
    P = L->next;
    while (P != NULL && strcmp(P->content,content) != 0)
        P = P->next;
    return P;
}

void insert(char * newContent, hashTable H){
    position pos,newCell;
    list L;
    pos = find(newContent,H);
    if(pos != NULL)
        return;

    newCell = malloc(sizeof(struct listNode));
    if(newCell == NULL){
        printf("Out of space!\n");
        return;
    }
    L = H->theList[hash(newContent, H->tableSize)];
    newCell->next = L->next;
    newCell->content = newContent;
    L->next = newCell;
}

void delete(char * oldContent,hashTable H){
    position preCell,oldCell;
    list L;

    L = H->theList[hash(oldContent, H->tableSize)];
    preCell = L;
    while (preCell->next != NULL && strcmp(preCell->next->content,oldContent) != 0)
        preCell = preCell->next;
    if(preCell->next)
        return;
    oldCell = preCell->next;
    preCell->next = preCell->next->next;
    free(oldCell);
}
/************ HASH TABLE END ************/
