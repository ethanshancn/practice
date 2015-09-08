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
        printf("Error in array length!\n");
        return;
    }
    int i = 0;
    printf("The array is :\n");
    while (i < totalNum){
        printf("key:%d, value:%d \n",i,array[i]);
        i++;
    }
}