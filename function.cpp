#include "function.h"
#include "math.h"


double Function:: calc(double x){
    if (_func =="sin")
        return sin(x);
    else if (_func =="cos")
        return cos(x);
    else if (_func =="tan")
        return  tan(x);
    else if (_func =="log")
        return  log(x);
    else if (_func =="sqrt")
        return  sqrt(x);
    else if (_func =="abs")
        return  abs(x);
    else if (_func =="exp")
        return  exp(x);
    else
        return x;

}
