/*
 * stackList.c : 
 * author     : ethan
 * createTime : 15/9/12 上午9:28
 * description:
 */
//

#include "stackList.h"
#include "list.h"

int isEmpty(stackList stack){
    return stack->next == NULL;
}

stackList createStack(){
    stackList result;
    result = malloc(sizeof(struct node));
    if(result == NULL)
        perror("Out of space!");
    result->next = NULL;
    makeEmpty(result);
    return result;
}

void makeEmpty(stackList stack){
    if (stack == NULL)
        perror("Must use createStack first!");
    else
        while (!isEmpty(stack))
            pop(stack);
}

void push (elementType content, stackList stack){
    ptrToNode tmpCell = malloc(sizeof(struct node));
    if(tmpCell == NULL)
        perror("Out of space!");
    else{
        tmpCell->element = content;
        tmpCell->next = stack->next;
        stack->next = tmpCell;
    }
}

elementType pop(stackList stack){
    elementType result = 0;
    if(isEmpty(stack)){
        perror("Empty stack!");
    }else{
        ptrToNode firstCell;
        firstCell = stack->next;
        stack->next = firstCell->next;
        result = firstCell->element;
        free(firstCell);
    }
    return result;
}