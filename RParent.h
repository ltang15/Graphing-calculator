#ifndef RPARENT_H
#define RPARENT_H
#include <iostream>
#include "Type.h"
#include "token.h"
class RParent: public Token
{
public:
    RParent (): _rp(')'){};


    TOKEN_TYPES type_of() {return RPARENT;}

    ostream& print(ostream& outs= cout) const {
        outs << _rp;
        return outs;
    }
private:
    char _rp;

};
#endif // RPARENT_H
