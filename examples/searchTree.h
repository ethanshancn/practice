/*
 * searchTree.h : 
 * author     : ethan
 * createTime : 15/9/12 下午3:29
 * description:
 */
//

#ifndef PRACTICE_SEARCHTREE_H
#define PRACTICE_SEARCHTREE_H

#include <stdlib.h>
#include <stdio.h>

struct treeNode;
typedef struct treeNode *position;
typedef struct treeNode *searchTree;
typedef int elementType;

searchTree makeEmpty(searchTree T);
position find(searchTree T, elementType X);
position findMin(searchTree T);
position findMax(searchTree T);
searchTree insert(elementType X, searchTree T); //根有可能发生变化
searchTree delete(elementType X, searchTree T);
elementType retrieve(position P);

#endif //PRACTICE_SEARCHTREE_H

struct treeNode{
    elementType content;
    searchTree left;
    searchTree right;
};