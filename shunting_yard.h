#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H


#include "token.h"
#include "queue.h"
#include "stack.h"

#include <iostream>
using namespace std;

class Shunting_yard
{
public:
    Shunting_yard(const Queue <Token*>& infix, int size);
    Queue <Token*> get_postfix ();
    Queue <Token*> postfix();
    friend ostream& operator<<(ostream& outs, const Shunting_yard& sy);

private:
    Queue <Token*> _postfix;
    Queue<Token*> _infix;
    int _size;
};

#endif // SHUNTING_YARD_H
