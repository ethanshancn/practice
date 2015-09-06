/*
 * baseArrayPro.c : 
 * author     : ethan
 * createTime : 15/9/5 下午7:26
 * description:
 */
//

#include "baseArrayCreat.h"

int createRadomArray(int *array,int totalNum, int min, int max){
    int i = 0;
    while (i < totalNum){
        array[i] = creatRandomInt(min,max);
        i++;
    }
}

int creatRandomInt(int min, int max){
    if (baseRandomSeed == 1){
        time_t nowTimeObj = time(NULL);
        if(nowTimeObj != -1){
            baseRandomSeed = (uintmax_t) nowTimeObj;
        }
    }

    long tmpSeed = BASE_RANDOM_INT_A * ( baseRandomSeed % BASE_RANDOM_INT_Q ) - BASE_RANDOM_INT_R * (  baseRandomSeed / BASE_RANDOM_INT_Q );
    if( tmpSeed > 0 ){
        baseRandomSeed = tmpSeed;
    }else{
        baseRandomSeed = tmpSeed + BASE_RANDOM_INT_M;
    }

    return  ( (double) baseRandomSeed / BASE_RANDOM_INT_M ) * ( max - min ) + min;
}