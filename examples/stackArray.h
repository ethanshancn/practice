/*
 * stackArray.h : 栈的数组实现
 * author     : ethan
 * createTime : 15/9/12 上午10:51
 * description:
 */
//

#ifndef PRACTICE_STACKARRAY_H
#define PRACTICE_STACKARRAY_H

#include <stdio.h>
#include <stdlib.h>

struct stackRecord;
typedef struct stackRecord *stack;
typedef int elementType;

int isEmpty (stack s);
int isFull (stack s);
stack createStack (int maxElements);
void disposeStack (stack s);    //释放栈全部的空间
void makeEmpty (stack s);
void push (elementType content, stack s);
elementType top (stack s);
elementType pop (stack s);

#define emptyTOS (-1)
#define minStackSize (5)

#endif //PRACTICE_STACKARRAY_H

struct stackRecord{
    int totalNum;
    int topOfSatck;
    elementType *array;
};