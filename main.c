/*
 * main.c : 
 * author     : ethan
 * createTime : 15/9/5 下午7:14
 * description:
 */
//

#include "main.h"

int main(int argc, char **agrv){

    /*int totalNum = 10;
    int arrData[totalNum] ;
    createRadomArray(arrData,totalNum,1,30);
    printIntArray(arrData,totalNum);    //打印数组*/

    polynomial polyA = NULL, polyB = NULL, tmpLastPoly, tmpPoly;
    int i;
    //第一个多项式
    i = 2;
    while (i-- > 0){
        tmpPoly = newPolynomial(creatRandomInt(1,5),creatRandomInt(i*3+1,i*3+3));
        if(polyA == NULL){
            polyA = tmpPoly;
        }else{
            tmpLastPoly->next = tmpPoly;
        }
        tmpLastPoly = tmpPoly;
    }

    //第二个多项式
    i = 3;
    while (i-- > 0){
        tmpPoly = newPolynomial(creatRandomInt(1,5),creatRandomInt(i*3+1,i*3+3));
        if(polyB == NULL){
            polyB = tmpPoly;
        }else{
            tmpLastPoly->next = tmpPoly;
        }
        tmpLastPoly = tmpPoly;
    }

    printf("###=>第一个多项式是：\n");
    printPolynomial(polyA);
    printf("###=>第二个多项式是：\n");
    printPolynomial(polyB);

    /*polynomial polySum = addPolynomial(polyA,polyB);
    printf("###=>相加之后的多项式是：\n");
    printPolynomial(polySum);*/

    polynomial polyMult = multPolynomial(polyA,polyB);
    printf("###=>相乘之后的多项式是：\n");
    printPolynomial(polyMult);

    return 0;
}

