#ifndef NUMBER_H
#define NUMBER_H


#include <iostream>
#include "Type.h"
#include "token.h"

class Number:public Token
{
public:
    Number():_num(NULL){};
    Number (double input): _num(input){};
    double num();

    TOKEN_TYPES type_of() {return NUMBER;}

    ostream& print(ostream& outs)const {
        outs << _num;
        return outs;
    }
private:
    double _num;
};
#endif // NUMBER_H
