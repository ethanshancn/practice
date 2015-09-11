//
// Created by Administrator on 2015/9/11.
//

#ifndef PRACTICE_POLYNOMIAL_H
#define PRACTICE_POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>

struct polyNode;
typedef struct polyNode *polyPtrToNode;
typedef polyPtrToNode polynomial;

void initPolynomial(polynomial poly);

polynomial newPolynomial (int coefficient, int exponent);

void addPolynomial(const polynomial poly1, const polynomial poly2, const polynomial polySum);

void multPolynomial(const polynomial poly1, const polynomial poly2, const polynomial polyMult);

void printPolynomial(polynomial poly);

#endif //PRACTICE_POLYNOMIAL_H

struct polyNode{
    int coefficient;    //系数
    int exponent;   //指数
    polyPtrToNode next;
};
