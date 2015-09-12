/*
 * stackArray.c : 
 * author     : ethan
 * createTime : 15/9/12 上午10:51
 * description:
 */
//

#include "stackArray.h"

int isEmpty (stack s){
    return s->topOfSatck == emptyTOS;
}

int isFull (stack s){
    return !(s->topOfSatck < s->totalNum);
}

stack createStack (int maxElements){
    stack result;
    if(maxElements < minStackSize){
        perror("Stack size is too small!");
    }
    result = malloc(sizeof(struct stackRecord));
    if(result == NULL){
        perror("Out of space!");
    }

    result->array = malloc(sizeof(elementType) * maxElements);
    if(result->array == NULL){
        perror("Out of space!");
    }
    result->totalNum = maxElements;
    makeEmpty(result);
    return result;
}

void disposeStack (stack s){
    if(s != NULL){
        free(s->array);
        free(s);
    }
}

void makeEmpty (stack s){
    s->topOfSatck = emptyTOS;
}

void push (elementType content, stack s){
    if(isFull(s)) {
        perror("Stack is full!");
        return;
    }
    s->array[++s->topOfSatck] = content;
}

elementType top (stack s){
    if(isEmpty(s)){
        printf("Empty stack!\n");
        return 0;
    }
    return s->array[s->topOfSatck];
}

elementType pop (stack s){
    if(isEmpty(s)){
        printf("Empty stack!\n");
        return 0;
    }
    elementType result = s->array[s->topOfSatck--];
    return result;
}
