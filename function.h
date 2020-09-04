#ifndef FUNCTION_H
#define FUNCTION_H


#include "token.h"
#include "Type.h"
#include <iostream>
#include <string>

class Function: public Token
{
public:
    Function(): _func(""){};
    Function (string func): _func (func){};
    TOKEN_TYPES type_of() {return FUNCTION;}
    double calc(double x);
    ostream& print(std::ostream& outs) const{
        outs << _func;
        return outs;
    }
private:
    string _func;

};
#endif // FUNCTION_H
