//
// Created by Administrator on 2015/9/11.
//

#include "polynomial.h"

void initPolynomial(polynomial poly){
    poly->exponent = 0;
    poly->coefficient = 0;
    if(poly->next != NULL){
        initPolynomial(poly->next);
        free(poly->next);
    }
}

polynomial newPolynomial (int coefficient, int exponent){

}

void addPolynomial(const polynomial poly1, const polynomial poly2, const polynomial polySum){





}

void multPolynomial(const polynomial poly1, const polynomial poly2, const polynomial polyMult){

}

void printPolynomial(polynomial poly){

}