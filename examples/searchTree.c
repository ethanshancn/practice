/*
 * searchTree.c : 
 * author     : ethan
 * createTime : 15/9/12 下午3:29
 * description:
 */
//

#include "searchTree.h"

searchTree makeEmpty(searchTree T){
    if(T != NULL){
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
    return NULL;
}

position find(searchTree T, elementType X){
    if(T == NULL){
        printf("Tree is NULL");
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

position findMin(searchTree T){
    if(T == NULL){
        return NULL;
    }
    if(T->left != NULL){
        findMin(T->left);
    }else{
        return T;
    }
}

position findMax(searchTree T){
    if(T == NULL){
        return NULL;
    }
    if(T->right == NULL){
        return T;
    }else{
        findMax(T->right);
    }
}

searchTree insert(elementType X, searchTree T){
    if(T == NULL){
        T = malloc(sizeof(struct treeNode));
        if(T == NULL){
            perror("Out of space!");
            return NULL;
        }
        T->content = X;
        T->left = T->right = NULL;
    }else if(X < T->content){
        T->left = insert(X,T->left);
    }else if(X > T->content){
        T->right = insert(X,T->right);
    }
    return T;
}

searchTree delete(elementType X, searchTree T){
    position tmpCell;
    if(T == NULL){
        printf("Element not found!");
        return NULL;
    }
    if(X < T->content){
        T->left = delete(X,T->left);
    }else if(X > T->content){
        T->right = delete(X,T->right);
    }else if(T->left && T->right){  //have two children
        tmpCell = findMin(T->right);
        T->content = tmpCell->content;
        T->right = delete(T->content,T->right); //递归的去删除右子树中的最小值
    }else{  //have one child
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
    return P->content;
}