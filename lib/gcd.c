/*
 * gcd.c : 
 * author     : ethan
 * createTime : 15/9/8 下午9:16
 * description:
 */
//

#include "gcd.h"

unsigned int gcd(unsigned int paramA, unsigned int paramB){
    unsigned int rem;
    while ( paramB > 0 ){
        rem = paramA % paramB;
        paramA = paramB;
        paramB = rem;
    }
    return paramA;
}