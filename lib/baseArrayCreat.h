/*
 * baseArrayPro.h : 
 * author     : ethan
 * createTime : 15/9/5 下午7:26
 * description:
 */
//

#ifndef PRACTICE_BASEARRAYCREAT_H
#define PRACTICE_BASEARRAYCREAT_H

#ifndef BASE_RANDOM_INT_A
#define BASE_RANDOM_INT_A 48271
#endif

#ifndef BASE_RANDOM_INT_M
#define BASE_RANDOM_INT_M 2147483647
#endif

#ifndef BASE_RANDOM_INT_Q
#define BASE_RANDOM_INT_Q ( BASE_RANDOM_INT_M / BASE_RANDOM_INT_A )
#endif

#ifndef BASE_RANDOM_INT_R
#define BASE_RANDOM_INT_R ( BASE_RANDOM_INT_M % BASE_RANDOM_INT_A )
#endif

#include <stdio.h>
#include <time.h>
#include <stdint.h>

#endif //PRACTICE_BASEARRAYPRO_H

//随机数发生种子
static unsigned long baseRandomSeed = 1;
//生成某一区间中的随即数
int creatRandomInt(int min, int max);
//生成指定大小的随机正整数数组
int createRadomArray(int *array,int totalNum, int min, int max);