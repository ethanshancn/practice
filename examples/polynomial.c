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

//合并同类项
void mergeSameExp (polynomial poly){
    int changedTimes = 0;
    polynomial tmpNowNode,tmpOtherNode,tmpOtherLastNode;

    tmpNowNode = poly;
    while (tmpNowNode != NULL){
        tmpOtherNode = tmpNowNode->next;
        tmpOtherLastNode = tmpNowNode;

        while (tmpOtherNode != NULL){
            if(tmpNowNode->exponent == tmpOtherNode->exponent){
                tmpNowNode->coefficient += tmpOtherNode->coefficient;
                tmpOtherLastNode->next = tmpOtherNode->next;
                free(tmpNowNode);
                changedTimes ++;
            }else{
                tmpOtherLastNode = tmpOtherNode;
            }
            tmpOtherNode = tmpOtherLastNode->next;
        }

        tmpNowNode = tmpNowNode->next;
    }

    if(changedTimes > 0){
        mergeSameExp(poly);
    }
}

//此处两个多项式指数已经按照从大到小的顺序进行了排序
polynomial multPolynomial(const polynomial polyA, const polynomial polyB){
    polynomial polyMult = NULL,tmpA,tmpB,tmpNowNode,tmpLastNode;

    for(tmpA = polyA; tmpA != NULL; tmpA = tmpA->next){
        for(tmpB = polyB;tmpB != NULL; tmpB = tmpB->next){
            tmpNowNode = newPolynomial(tmpA->coefficient * tmpB->coefficient,tmpA->exponent + tmpB->exponent);
            if (polyMult == NULL){
                polyMult = tmpNowNode;
            }else{
                tmpLastNode->next = tmpNowNode;
            }
            tmpLastNode = tmpNowNode;
        }
    }

    mergeSameExp(polyMult);
    return polyMult;
}

void printPolynomial(polynomial poly){
    printf("当前项的系数是：%d ,当前项的指数是：%d \n",poly->coefficient,poly->exponent);
    if(poly->next != NULL){
        printPolynomial(poly->next);
    }
}

void freePolynomial(polynomial poly){
    if(poly == NULL){
        return;
    }
    if(poly->next != NULL){
        freePolynomial(poly->next);
    }
    free(poly);
}