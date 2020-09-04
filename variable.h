#ifndef VARIABLE_H
#define VARIABLE_H


#include "token.h"
#include "Type.h"

class Variable: public Token
{
public:

    Variable(): _var('x'){};

    TOKEN_TYPES type_of () {return VARIABLE;}
    ostream& print(std::ostream& outs) const{
        outs <<_var;
        return outs;

    }
private:
    char _var;

};
#endif // VARIABLE_H
