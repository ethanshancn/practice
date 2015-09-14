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



    return 0;
}

