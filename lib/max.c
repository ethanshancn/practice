/*
 * max.c : 
 * author     : ethan
 * createTime : 15/9/11 下午8:07
 * description:
 */
//

#include "max.h"

int maxInt(int paramA, int paramB){
    int result = (paramA > paramB) ? paramA : paramB;
    return result;
}