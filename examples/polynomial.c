//
// Created by Administrator on 2015/9/11.
//

#include "polynomial.h"

void zeroPolynomial(polynomial poly){
    poly->exponent = 0;
    poly->coefficient = 0;
    if(poly->next != NULL){
        zeroPolynomial(poly->next);
    }
    poly->next = NULL;
}

void addPolynomial(const polynomial poly1, const polynomial poly2, const polynomial polySum){

}

void multPolynomial(const polynomial poly1, const polynomial poly2, const polynomial polyMult){

}

void printPolynomial(polynomial poly){

}