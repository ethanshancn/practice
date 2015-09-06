/*
 * sortProblem.c : 排序问题
 * author     : ethan
 * createTime : 15/9/6 下午8:43
 * description:
 */
//

#include "sortProblem.h"

void insertSort(int array[], int totalNum){
    int i,j;
    for(i = 1; i < totalNum; ++i){
        int tmp = array[i];
        for(j = i; j > 0 && array[j - 1] > tmp; j--){
            array[j] = array[j - 1];
        }
        array[j] = tmp;
    }
}

void shellSort(int array[], int totalNum){
    int i, j, increament;
    int tmp;

}