/*
 * binHeap.c : 
 * author     : ethan
 * createTime : 15/10/1 下午3:27
 * description:
 */
//

#include "binHeap.h"

priorityQueue initialize(int totalNum){
    priorityQueue H;

    if(totalNum < 0){
        printf("Priority queue size is too small!");
        return NULL;
    }
    H = malloc(sizeof(struct heapStruct));
    if(H == NULL){
        printf("Out of space!");
        return NULL;
    }

    H->content = malloc((totalNum + 1) * sizeof(elementType));
    if(H->content == NULL){
        printf("Out of space!");
        return NULL;
    }

    H->capacity = totalNum;
    H->size = 0;
    H->content[0] = -99999;
}

void destroy(priorityQueue H){

}

void makeEmpty( priorityQueue H){

}

void insert (elementType X, priorityQueue H){
    int i;
    if(isFull(H)){
        printf("Prioruty queue is full!");
        return;
    }
    for(i = ++H->size;H->content[i / 2]> X; i /= 2){
        H->content[i] = H->content[i / 2];
    }
    H->content[i] = X;
}

elementType deleteMin(priorityQueue H){
    int i, child;
    elementType minElement,lastElement;

    if(isEmpty(H)){
        printf("Priority queue is empty!");
        return NULL;
    }

    minElement = H->content[1];
    lastElement = H->content[H->size--];

    for (int i = 1; i * 2 <= H->size; i = child) {
        child = i *2;
        if(child != H->size && H->content[child + 1] < H->content[child])
            child++;
        if(lastElement > H->content[child]){
            H->content[i] = H->content[child];
        }else{
            break;
        }
        H->content[i] = lastElement;
        return minElement;
    }




}

elementType FindMin(priorityQueue H){

}

int isEmpty(priorityQueue H){

}

int isFull(priorityQueue H){

}
