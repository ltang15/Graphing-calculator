#ifndef TOKEN_H
#define TOKEN_H


#include <iostream>
#include "Type.h"

using namespace std;
class Token
{
public:
    Token(){};
    virtual TOKEN_TYPES type_of(){return OPERATOR;}
    virtual int precedence (){return -1;}
    virtual ostream& print(ostream& outs=cout)const {return outs;}
    friend ostream& operator <<(ostream& outs, const Token& t){
        return t.print(outs);
    }
    friend ostream& operator <<(ostream& outs, Token *t){
        return t->print(outs);
    }
};
#endif // TOKEN_H
