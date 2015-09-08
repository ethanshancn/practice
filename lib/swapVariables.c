/*
 * swapVariables.c : 
 * author     : ethan
 * createTime : 15/9/7 下午10:24
 * description:
 */
//

#include "swapVariables.h"

void swapArrayVal(int *paramA, int *paramB){
    int tmp = *paramA;
    *paramA = *paramB;
    *paramB = tmp;
}