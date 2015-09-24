/*
 * createPrime.h : 
 * author     : ethan
 * createTime : 15/9/23 下午11:37
 * description:
 */
//

#ifndef PRACTICE_CREATEPRIME_H
#define PRACTICE_CREATEPRIME_H

typedef unsigned char byte;

byte * initContainer(int totalSize);    //Malloc and remember to free

int bytePosition(int nowLocation);

byte newByte(byte nowByte,int bytePos);


#endif //PRACTICE_CREATEPRIME_H
