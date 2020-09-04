#ifndef LPARENT_H
#define LPARENT_H
#include <iostream>
#include "Type.h"
#include "token.h"
class LParent:public Token
{
public:
    LParent (): _lp ('('){};


    TOKEN_TYPES type_of() {return LPARENT;}

    ostream& print(ostream& outs= cout) const {
        outs << _lp;
        return outs;
    }
private:
    char _lp;
};
#endif // LPARENT_H
