/*
 * binHeap.h : 
 * author     : ethan
 * createTime : 15/10/1 下午3:27
 * description:
 */
//

#ifndef PRACTICE_BINHEAP_H
#define PRACTICE_BINHEAP_H

struct heapStruct;
typedef struct heapStruct *priorityQueue;
typedef int elementType;

priorityQueue initialize(int maxElement);
void destroy(priorityQueue H);
void makeEmpty( priorityQueue H);
void insert (elementType X, priorityQueue H);
elementType deleteMin(priorityQueue H);
elementType FindMin(priorityQueue H);
int isEmpty(priorityQueue H);
int isFull(priorityQueue H);

struct heapStruct{
    int capacity;
    int size;
    elementType *content;
};

#endif //PRACTICE_BINHEAP_H
