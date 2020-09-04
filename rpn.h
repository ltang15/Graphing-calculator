#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <token.h>
#include "queue.h"
#include "stack.h"

#include "queue.h"
#include "stack.h"
#include "token.h"

class RPN
{
public:
    RPN();
    RPN(Queue <Token*> input);
    double operator ()(const double& value);
    friend ostream& operator <<(ostream&outs, const RPN& print_me){
        outs << print_me._rpn << endl;
        return outs;
    }

private:
    Queue <Token*> _rpn;
};
#endif // RPN_H
