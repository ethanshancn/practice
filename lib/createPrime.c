/*
 * createPrime.c :
 * author     : ethan
 * createTime : 15/9/23 下午11:37
 * description:
 */

#include "createPrime.h"

byte *primeArray = NULL;
int primeArrLen = 0;
int lastTotalSize = 0;

void initContainer(int totalSize);    //Malloc and remember to free
int bytePosition(int nowSize);
byte newByte(byte nowByte,int bytePos);
void createPrimeTable(int largeNum);

void initContainer(int totalSize){
    if(primeArray != NULL || primeArrLen != 0){
        free(primeArray);
        primeArrLen = 0;
    }

    int mainNum = totalSize >> 3;
    int remainNum = totalSize - (mainNum << 3);
    primeArrLen = (remainNum > 0)?(mainNum + 1) : mainNum;
    primeArray = malloc(sizeof(byte) * primeArrLen);
    if(primeArray == NULL){
        printf("Out of space!\n");
        return;
    }

    int i = 0;
    for(i = 0 ; i < primeArrLen - 1; ++i){
        primeArray[i] = 0xFF;
    }
    primeArray[primeArrLen - 1] = (remainNum > 0)?(0xFF << (8-remainNum)) : 0xFF;
}

int bytePosition(int nowSize){
    int remainLoc = nowSize - ((nowSize >> 3) << 3);
    return (remainLoc > 0)?remainLoc:8;
}

byte newByte(byte nowByte,int bytePos){
    byte assistyte = ~(1 << (8 - bytePos));
    return assistyte & nowByte;
}

int getNowStatus(int nowSize){
    if(primeArray == NULL || nowSize > lastTotalSize){
        printf("Error in array length!\n");
        return -1;
    }
    int location = nowSize >> 3;
    int position = bytePosition(nowSize);
    byte assistyte = 1 << (8-position);
    return (assistyte & primeArray[location]) >> (8-position);
}

void createPrimeTable(int totalSize){
    initContainer(totalSize);
    lastTotalSize = totalSize;
    int startNum = 1;
    int multipleNum = 2;
    int nowLocation = 0;
    int nowSize = 0;
    while (startNum <= totalSize){
        while (getNowStatus(++startNum) != 1){
            if(startNum > totalSize){
                return;
            }
        }

        for(multipleNum = 2 ; (nowSize = multipleNum * startNum) <= lastTotalSize; ++multipleNum){
            nowLocation = nowSize >> 3;
            primeArray[nowLocation] = newByte(primeArray[nowLocation],bytePosition(nowSize));
        }
    }
}

int getCloseinLargerNum(int N){
    if(N <= 1)
        return 1;
    int newTotalSize = N + log(N) * 3;
    if(newTotalSize > lastTotalSize)
        createPrimeTable(newTotalSize);
    int i = N;
    for(i = N ;i < newTotalSize; ++i){
        if(getNowStatus(i) == 1)
            return i;
    }
    return -1;
}
