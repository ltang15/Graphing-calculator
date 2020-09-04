#include "operator.h"
#include <cstring>
#include <cmath>
using namespace std;


Operator::Operator (string expression){
    _op = expression;
   if (_op == "+" || _op == "-")
       _prec = 1;
   else if (_op == "*" ||_op =="/")
       _prec=2;
   else if (_op == "^")
       _prec=3;
   else
       _prec = -1;
}

int Operator::precedence (){
    if (_op =="-" || _op=="+")
        return 1;
    else if (_op=="*" || _op=="/")
        return 2;
    else if (_op == "^")
        return 3;
    else
        return -1;

}
double Operator::calc(double num1, double num2) {

    if (_op =="+")
        return num1 + num2;
    else if (_op=="-")
        return num1 - num2;
    else if (_op == "*")
        return  num1 * num2;
    else if (_op == "/")
        return  num1 / num2;
    else if (_op == "^")
        return pow(num1, num2);
    else
        return num1;
}
