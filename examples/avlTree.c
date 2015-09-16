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

static int height(position P){
    if(P == NULL)
        return -1;
    else
        return P->height;
}

static position singleRotateWithLeft(position K2){
    position K1;
    K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;
    K2->height = maxInt(height(K2->left),height(K2->right)) + 1;
    K1->height = maxInt(height(K1->left),height(K1->right)) + 1;
    return K1;
}

static position singleRotateWithRight(position K2){
    position K1;
    K1 = K2->right;
    K2->right = K1->left;
    K1->left = K2;
    K2->height = maxInt(height(K2->left),height(K2->right)) + 1;
    K1->height = maxInt(height(K1->left),height(K1->right)) + 1;
    return K1;
}

static position doubleRotateWithLeft(position K3){
    K3->left = singleRotateWithRight(K3->left);
    return singleRotateWithLeft(K3);
}

static position doubleRotateWithRight(position K3){
    K3->right = singleRotateWithLeft(K3->right);
    return singleRotateWithRight(K3);
}

avlTree insert(elementType X, avlTree T){

}

avlTree delete(elementType X, avlTree T){

}

elementType retrieve(position P){

}