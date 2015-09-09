/*
 * list.c : 
 * author     : ethan
 * createTime : 15/9/8 下午10:23
 * description:
 */
//

#include "list.h"

void makeEmpty(list exList){
    if(exList->next != NULL){
        deleteList(exList);
    }
}

int isEmpty (list exList){
    int result = 0;
    if(exList->next == NULL){
        result = 1;
    }
    return result;
}

int isLast (position exPosition, list exList){
    int result = 0;
    if(exPosition->next == NULL){
        result = 1;
    }
    return result;
}

position find(elementType nodeContent,list exList){
    position tmp;
    tmp = exList->next;
    while (tmp->element != nodeContent){
        tmp = tmp->next;
    }
    return tmp;
}

void delete(elementType nodeContent, list exList){
    position pre, tmp;
    pre = findPrevious(nodeContent, exList);
    if(!isLast(pre,exList)){
        tmp = pre->next;
        pre->next = tmp->next;
        free(tmp);
    }
}

position findPrevious(elementType nodeContent, list exList){
    position tmp;
    tmp = exList;
    while (tmp->next != NULL && tmp->next->element != nodeContent){
        tmp = tmp->next;
    }
    return tmp;
}

void insert(elementType newContent, list exList, position periousPos){
    position tmp;
    tmp = malloc(sizeof(struct node));
    if(tmp == NULL){

    }
    tmp->element = newContent;
    tmp->next = periousPos->next;
    periousPos->next = tmp;
}

void deleteList(list exList){

}

position header(list exList){

}

position first(list exList){

}

position advance(position exPositon){

}

elementType retrieve(position exPosition){

}
