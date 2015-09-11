//
// Created by Administrator on 2015/9/11.
//

#ifndef PRACTICE_POLYNOMIAL_H
#define PRACTICE_POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include "../lib/max.h"

struct polyNode;
typedef struct polyNode *polyPtrToNode;
typedef polyPtrToNode polynomial;

polynomial newPolynomial (int coefficient, int exponent);

polynomial addPolynomial(const polynomial polyA, const polynomial polyB);

polynomial multPolynomial(const polynomial polyA, const polynomial polyB);

void printPolynomial(polynomial poly);

void freePolynomial(polynomial poly);

#endif //PRACTICE_POLYNOMIAL_H

struct polyNode{
    int coefficient;    //系数
    int exponent;   //指数
    polyPtrToNode next;
};
