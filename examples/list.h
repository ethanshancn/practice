/*
 * list.h : 
 * author     : ethan
 * createTime : 15/9/8 下午10:23
 * description:
 */
//

#ifndef PRACTICE_LIST_H
#define PRACTICE_LIST_H

#include <stdlib.h>

struct node;
typedef struct node *ptrToNode;
typedef ptrToNode list;
typedef ptrToNode position;
typedef int elementType;

void makeEmpty(list exList);
int isEmpty (list exList);
int isLast (position exPosition, list exList);
position find(elementType nodeContent,list exList);
void delete(elementType nodeContent, list exList);
position findPrevious(elementType nodeContent, list exList);
void insert(elementType newContent, list exList, position periousPos);
void deleteList(list exList);
position header(list exList);
position first(list exList);
position advance(position exPositon);
elementType retrieve(position exPosition);

#endif //PRACTICE_LIST_H

struct node{
    elementType element;
    position next;
};