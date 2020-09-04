#include "rpn.h"
#include "operator.h"
#include "number.h"
#include "Type.h"
#include "function.h"

RPN::RPN(){}

RPN::RPN(Queue <Token*> input){
    _rpn = input;
}


double RPN::operator ()(const double& value){
    Stack <Token*> s;
    Token* ptr_2_left;
    Token* ptr_2_right;
    Token* ptr_res;
    Token* final;
    double left, right, val;
    double result, final_result;
    Token* item;
    int type;
    Queue<Token*>::Iterator walker = _rpn.Begin();


    while (walker != _rpn.End()) {


           item =*walker; //token pointer pointing to a number, operator or ...

           walker++;
           type = item ->type_of();

           switch(type) {

               case NUMBER:
                   s.push(item);
                   break;

               case VARIABLE:{
                    //cout << "rpn x" << endl;
                    s.push (new Number (value));
                    break;
               }

               case FUNCTION:{
                   // pop the number from the stack
                   // put it into the function -> calc, push the result back to the stack

                    ptr_res =s.pop();
                    val = static_cast<Number*>(ptr_res)->num();
                    result = static_cast<Function*> (item) ->calc (val);
                    s.push(new Number(result));


                   break;
               }

               case OPERATOR:{
                   // pop out 2 numbers from the stack,
                   //then call the calc from the operator class
                   ptr_2_right = s.pop();
                   ptr_2_left = s.pop();
                   right = static_cast<Number*>(ptr_2_right)->num();
                   left = static_cast<Number*>(ptr_2_left)->num();
                   result = static_cast<Operator*> (item) ->calc (left, right);

                   s.push(new Number(result));
                   break;
                }

           }

   }

    final = s.pop();

    final_result = static_cast<Number*>(final)->num();
    return final_result;
}
