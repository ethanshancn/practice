/*
 * maxSubSequenceSum.c : 求最大子序列和
 * author     : ethan
 * createTime : 15/9/6 下午8:18
 * description:
 */
//

#include "maxSubSequenceSum.h"
int maxSubSequenceSum(int array[], int totalNum){
    int thisSum,maxSum;
    thisSum = maxSum = 0;
    int i = 0;
    while(i++ < totalNum){
        thisSum += array[i];
        if(thisSum > maxSum){
            maxSum = thisSum;
        }else{
            thisSum = 0;
        }
    }
    return  maxSum;
}