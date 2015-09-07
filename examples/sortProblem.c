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

    for(increament = (int)(totalNum/2);increament > 0 ; increament = (int)(increament/2)){
        for (int i = increament; i < totalNum; ++i) {
            tmp = array[i];
            for (int j = i; j >= increament; j -= increament) {
                if(tmp < array[j-increament]){
                    array[j] = array[j-increament];
                }else{
                    break;
                }
            }
            array[j] = tmp;
        }
    }
}

//建立最大堆，该堆从0索引开始,父节点总比子节点大
void buildMaxHeap(int array[],int i, int totalNum){
    int child;
    int tmp;

    for (tmp = array[i]; (2 * i +1) < totalNum; i = child) {
        child = 2 * i +1;
        if(child != totalNum-1 && array[child+1]>array[child]){
            child ++;
        }
        if(array[child] > tmp){
            array[i] = array[child];
        }else{
            break;
        }
    }
    array[i] = tmp;
}

void heapSort(int array[], int totalNum){
    int i;

    for (i = (int)(totalNum / 2); i >= 0; i--) {
        buildMaxHeap(array,i,totalNum);
    }
    for (i = totalNum - 1; i > 0; --i) {
        swapArrayVal(&array[0],&array[i]);
        buildMaxHeap(array,0,i);
    }


}