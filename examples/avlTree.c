/*
 * avlTree.c : 
 * author     : ethan
 * createTime : 15/9/14 下午7:32
 * description:
 */
//

#include "avlTree.h"

avlTree makeEmpty(avlTree T){
    if(T != NULL){
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
    return NULL;
}

position find(elementType X, avlTree T){
    if(T == NULL){
        printf("Tree is NULL \n");
        return NULL;
    }
    if(X < T->content){
        return find(X,T->left);
    }else if(X > T->content){
        return find(X,T->right);
    }else{
        return T;
    }
}

position findMin(avlTree T){
    if (T == NULL){
        return NULL;
    }else if(T->left == NULL){
        return T;
    }else{
        return findMin(T);
    }
}

position findMax(avlTree T){
    if(T != NULL)
        while (T->right != NULL)
            T = T->right;
    return T;
}

avlTree insert(elementType X, avlTree T){

}

avlTree delete(elementType X, avlTree T){

}

elementType retrieve(position P){

}