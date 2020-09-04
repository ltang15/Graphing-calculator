#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include "token.h"
#include "Type.h"
#include "number.h"
using namespace std;

class Operator:public Token
{
public:
    Operator();
    Operator (string expression);
    TOKEN_TYPES type_of() {return OPERATOR;}
    double calc(double num1, double num2);

    int precedence ();
    ostream& print(ostream& outs)const {
        outs << _op;
        return outs;
    }
private:
    string _op;
    int _prec;
};
#endif // OPERATOR_H
