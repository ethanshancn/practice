/*
 * searchProblem.c : 
 * author     : ethan
 * createTime : 15/9/8 下午9:05
 * description:
 */
//

#include "searchProblem.h"

int binarySearch(int array[],int totalNum, int find){
    int left,right,center;
    left = 0;
    right = totalNum-1;
    while(left <= right){
        center = (left + right) / 2;
        if(find < array[center]){
            right = center-1;
        }else if(find > array[center]){
            left = center +1;
        }else{
            return  center;
        }
    }
    return -1;
}