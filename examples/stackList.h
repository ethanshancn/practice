/*
 * stackList.h : 栈的链表实现
 * author     : ethan
 * createTime : 15/9/12 上午9:28
 * description:
 */
//

#ifndef PRACTICE_STACKLIST_H
#define PRACTICE_STACKLIST_H

#include <stdlib.h>
#include <stdio.h>

struct node;
typedef struct node *ptrToNode;
typedef ptrToNode stackList;    //作为表头，push、pop都对应操作其next

typedef int elementType;

int isEmpty(stackList stack);
stackList createStack();
void makeEmpty(stackList stack);
void push (elementType content, stackList stack);
elementType pop(stackList stack);

#endif //PRACTICE_STACKLIST_H

struct node{
    elementType element;
    ptrToNode next;
};