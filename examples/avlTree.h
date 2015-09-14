/*
 * avlTree.h : 
 * author     : ethan
 * createTime : 15/9/14 下午7:32
 * description:
 */
//

#ifndef PRACTICE_AVLTREE_H
#define PRACTICE_AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

struct avlNode;
typedef struct avlNode *position;
typedef position avlTree;
typedef int elementType;

avlTree makeEmpty(avlTree T);
position find(elementType X, avlTree T);
position findMin(avlTree T);
position findMax(avlTree T);
avlTree insert(elementType X, avlTree T);
avlTree delete(elementType X, avlTree T);
elementType retrieve(position P);

#endif //PRACTICE_AVLTREE_H

struct avlNode{
    elementType element;
    avlTree left;
    avlTree right;
    int height;
};