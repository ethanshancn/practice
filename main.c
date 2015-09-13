/*
 * main.c : 
 * author     : ethan
 * createTime : 15/9/5 下午7:14
 * description:
 */
//

#include "main.h"

int main(int argc, char **agrv){

    int totalNum = 30;
    int arrData[totalNum] ;
    createRadomArray(arrData,totalNum,1,100);
    printIntArray(arrData,totalNum);    //打印数组

    searchTree T = NULL;
    int i = 0;
    for (int i = 0; i < totalNum; ++i) {
        T = insert(arrData[i],T);
    }
    printf("初始化完成时的查找树\n");
    printTree(T);

    T = delete(arrData[4],T);
    printf("删除数组下标4的值之后的树\n");
    printTree(T);


    return 0;
}

