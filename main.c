/*
 * main.c : 
 * author     : ethan
 * createTime : 15/9/5 下午7:14
 * description:
 */
//

#include "main.h"

int main(int argc, char **agrv){

    int totalNum = 10;
    int arrData[totalNum] ;
    createRadomArray(arrData,totalNum,-20,20);
    printIntArray(arrData,totalNum);    //打印数组

    insertSort(arrData,totalNum);
    printf("排序之后的数组是：\n");
    printIntArray(arrData,totalNum);

    return 0;
}

