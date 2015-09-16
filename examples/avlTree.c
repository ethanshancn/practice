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
    if( T == NULL ){
        T = malloc(sizeof(struct avlNode));
        if( T == NULL)
            perror("Out of space !");
        else{
            T->content = X;
            T->height = 0;
            T->left = T->right = NULL;
        }
    }else if( X < T->content){
        T->left = insert(X,T->left);
        if(height(T->left) - height(T->right) == 2)
            T = singleRotateWithLeft(T);
        else
            T = doubleRotateWithLeft(T);
    }else if( X > T->content){
        T->right = insert(X,T->right);
        if(height(T->right) - height(T->left) == 2)
            T = singleRotateWithRight(T);
        else
            T = doubleRotateWithRight(T);
    }
    T->height = maxInt(height(T->left),height(T->right)) + 1;
    return T;
}

avlTree delete(elementType X, avlTree T){
    position tmpCell;
    if(T == NULL){
        printf("Element not found! \n");
        return NULL;
    }
    if(X < T->content){
        T->left = delete(X,T->left);
        if(height(T->right) - height(T->left) == 2)
            T = singleRotateWithRight(T);
        else
            T = doubleRotateWithRight(T);
    }else if(X > T->content){
        T->right = delete(X,T->right);
        if(height(T->left) - height(T->right) == 2)
            T = singleRotateWithLeft(T);
        else
            T = doubleRotateWithLeft(T);
    }else if(T->left && T->right){  //have 2 children
        tmpCell = findMin(T->right);
        T->content = tmpCell->content;
        T->right = delete(T->content,T->right); //递归的去删除右子树中的最小值
        if(height(T->left) - height(T->right) == 2)
            T = singleRotateWithLeft(T);
        else
            T = doubleRotateWithLeft(T);
    }else{  //have 1 or 0 child
        tmpCell = T;
        if(T->left == NULL)
            T = T->right;
        else if(T->right == NULL)
            T = T->left;
        free(tmpCell);
    }
    return T;
}

elementType retrieve(position P){
    if(P == NULL)
        return NULL;
    else
        return P->content;
}