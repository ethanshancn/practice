//
// Created by Administrator on 2015/9/11.
//

#include "polynomial.h"

polynomial newPolynomial (int coefficient, int exponent){
    polynomial tmp;
    tmp = malloc(sizeof(struct polyNode));
    tmp->coefficient = coefficient;
    tmp->exponent = exponent;
    tmp->next = NULL;
    return tmp;
}

//此处两个多项式指数已经按照从大到小的顺序进行了排序
polynomial addPolynomial(const polynomial polyA, const polynomial polyB){
    int nowExp = 0; //初始化最高指数
    polynomial polySum = NULL,tmpA,tmpB,tmpNowNode,tmpLastNode;
    tmpA = polyA,tmpB = polyB;
    do{
        if(tmpA == NULL || tmpB == NULL){
            break;
        }

        nowExp = maxInt(tmpA->exponent,tmpB->exponent);
        tmpNowNode = newPolynomial(0,nowExp);
        if(tmpA->exponent == nowExp){
            tmpNowNode->coefficient += tmpA->coefficient;
            tmpA = tmpA->next;
        }
        if(tmpB->exponent == nowExp){
            tmpNowNode->coefficient += tmpB->coefficient;
            tmpB = tmpB->next;
        }

        if (polySum == NULL){
            polySum = tmpNowNode;
        }else{
            tmpLastNode->next = tmpNowNode;
        }
        tmpLastNode = tmpNowNode;
    }while (1);

    if(tmpA != NULL){
        tmpLastNode->next = tmpA;
    }else if(tmpB != NULL){
        tmpLastNode->next = tmpB;
    }
    return polySum;
}

//此处两个多项式指数已经按照从大到小的顺序进行了排序
polynomial multPolynomial(const polynomial polyA, const polynomial polyB){

}

void printPolynomial(polynomial poly){

}

void freePolynomial(polynomial poly){

}