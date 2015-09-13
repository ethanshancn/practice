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

position findMin(searchTree T){
    if(T == NULL){
        return NULL;
    }
    if(T->left != NULL)
        T = findMin(T->left);
    return T;
}

position findMax(searchTree T){
    if(T != NULL)
        while (T->right != NULL)
            T = T->right;
    return T;
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
        printf("Element not found! \n");
        return NULL;
    }
    if(X < T->content){
        T->left = delete(X,T->left);
    }else if(X > T->content){
        T->right = delete(X,T->right);
    }else if(T->left && T->right){  //have 2 children
        tmpCell = findMin(T->right);
        T->content = tmpCell->content;
        T->right = delete(T->content,T->right); //递归的去删除右子树中的最小值
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
    return P->content;
}

void printContent(elementType content,int depth){
    char space[depth+2];
    int i = 0;
    while (i < (depth + 1)){
        space[i] = 0x09;
        i ++;
    }
    space[i] = '\0';
    printf("%s(%d)节点内容:%d\n",space,depth,content);
}
void printT(searchTree T, int depth ){
    if(T == NULL)
        return;
    if(T->right != NULL)
        printT(T->right,depth+1);
    printContent(T->content,depth);
    if(T->left != NULL){
        printT(T->left,depth+1);
    }
}

void printTree(searchTree T){
    printT(T,0);
}