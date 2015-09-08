/* * sortProblem.c : 排序问题 * author     : ethan * createTime : 15/9/6 下午8:43 * description: *///#include "sortProblem.h"void insertSort(int array[], int totalNum){    int i,j;    for(i = 1; i < totalNum; ++i){        int tmp = array[i];        for(j = i; j > 0 && array[j - 1] > tmp; j--){            array[j] = array[j - 1];        }        array[j] = tmp;    }}void shellSort(int array[], int totalNum){    int i, j, increament;    int tmp;    for(increament = (int)(totalNum/2);increament > 0 ; increament = (int)(increament/2)){        for (i = increament; i < totalNum; ++i) {            tmp = array[i];            for (j = i; j >= increament; j -= increament) {                if(tmp < array[j-increament]){                    array[j] = array[j-increament];                }else{                    break;                }            }            array[j] = tmp;        }    }}//建立最大堆，该堆从0索引开始,父节点总比子节点大void buildMaxHeap(int array[],int i, int totalNum){    int child;    int tmp;    for (tmp = array[i]; (2 * i +1) < totalNum; i = child) {        child = 2 * i +1;        if(child != totalNum-1 && array[child+1]>array[child]){            child ++;        }        if(array[child] > tmp){            array[i] = array[child];        }else{            break;        }    }    array[i] = tmp;}void heapSort(int array[], int totalNum){    int i;    for (i = (int)(totalNum / 2); i >= 0; i--) {        buildMaxHeap(array,i,totalNum);    }    for (i = totalNum - 1; i > 0; --i) {        swapArrayVal(&array[0],&array[i]);        buildMaxHeap(array,0,i);    }}void merge(int array[], int tmpArray[], int lPos, int rPos, int rEnd){    int i, lEnd, totalNum, tmpPos;    lEnd = rPos - 1;    tmpPos = lPos;    totalNum = rEnd - lPos + 1;    while (lPos <= lEnd && rPos <= rEnd){        if(array[lPos] <= array[rPos]){            tmpArray[tmpPos++] = array[lPos++];        }else{            tmpArray[tmpPos++] = array[rPos++];        }    }    while (lPos <= lEnd){        tmpArray[tmpPos++] = array[lPos++];    }    while (rPos <= rEnd){        tmpArray[tmpPos++] = array[rPos++];    }    for(i = 0; i < totalNum; ++i,rEnd--){   //The 'totalNum' is refer to the tmp working length        array[rEnd] = tmpArray[rEnd];    }}void mSort(int array[], int tmpArray[],int left, int right){    int center;    if(left < right){        center = (left + right)/2;        mSort(array, tmpArray, left, center);        mSort(array, tmpArray, center+1, right);        merge(array, tmpArray, left, center+1, right);    }}void mergeSort(int array[], int totalNum){    int tmpArray[totalNum];    mSort(array, tmpArray, 0, totalNum-1);}int media3(int array[], int left, int right){    int center = (left + right) / 2;    if(array[left] > array[center]){        swapArrayVal(&array[left],&array[center]);    }    if(array[left] > array[right]){        swapArrayVal(&array[left],&array[right]);    }    if(array[center] > array[right]){        swapArrayVal(&array[center],&array[right]);    }    swapArrayVal(&array[center],&array[right-1]);   //由上可知，left比center小，right比center大，此时已排好序,因此排序从left+1到right-2    return array[right-1];}void qSort(int array[],int left, int right){    int i,j;    int pivot;    if(left +3 <= right){        pivot = media3(array,left,right);        i = left;j = right-1;        for (;;) {            while (array[++i] < pivot){}            while (array[--j] > pivot){}            if(i < j){                swapArrayVal(&array[i],&array[j]);            }else{                break;            }        }        swapArrayVal(&array[i],&array[right-1]);        qSort(array,left,i-1);        qSort(array,i+1,right);    }else{        insertSort(array+left,right-left+1);    }}void quickSort(int array[], int totalNum){    qSort(array,0,totalNum-1);}