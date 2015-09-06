/*
 * printArray.c : 
 * author     : ethan
 * createTime : 15/9/6 下午8:28
 * description:
 */
//

#include "printArray.h"
void printIntArray(int array[], int totalNum){
    if(totalNum <= 0 ){
        printf("数组长度传递错误!\n");
        return;
    }
    int i = 0;
    printf("当前数组为：\n");
    while (i < totalNum){
        printf("key:%d, value:%d \n",i,array[i]);
        i++;
    }
}