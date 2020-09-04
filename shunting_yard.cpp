#include "shunting_yard.h"
#include "operator.h"
#include "number.h"
#include "token.h"
#include "variable.h"
#include "function.h"



Shunting_yard::Shunting_yard(const Queue <Token*>& infix, int size){
    //get_postfix(input, size);
    _infix = infix;
   _postfix = get_postfix();
   _size = size;

}

Queue <Token*> Shunting_yard::get_postfix (){
    Stack <Token*> st;
    Queue <Token*> result;

    for (int i = 0;  !_infix.empty(); i++){
        Token* item = _infix.pop();

        int type = item ->type_of();

        switch (type){
            case NUMBER: {
                result.push(item);// push item into the queue if it's a number

                break;
            }
            case VARIABLE:{
            //cout << "shunting yard x" << endl;
                result.push(item);
                break;
            }
            case FUNCTION:{
                st.push(item);
                break;
            }

            case LPARENT:{


                st.push(item);
                break;
            }
            case RPARENT: {
            // pop all the token in the stack until it reaches the left parentheses


                type = st.top()->type_of();


                while (!st.empty() &&type != LPARENT){


                    Token* pop_st = st.pop ();
                    result.push(pop_st);
                    type = st.top()->type_of();
                }

                assert(!st.empty());
                st.pop(); // pop the left parentheses

                break;
            }
        case OPERATOR:{
            Operator* op = static_cast<Operator*>(item);

            if (!st.empty()){



                // if the prec of the op less than or equal to the prec of the top of stack
                while (!st.empty() && static_cast<Operator*> (st.top()) ->precedence() >= op->precedence()){


                    // pop the stack and push it into the queue
                    Token* pop_st = st.pop ();

                    result.push(pop_st);
                }

                st.push (op); // push into the stack when op > top of st
            }
            else
                st.push(op);// push op into the st if it's empty

            break;
        }

        }


    }
    cout<<endl;
    while (!st.empty()){
        result.push (st.pop());
    }
    return result;
}


Queue<Token*> Shunting_yard::postfix(){

    return _postfix;
}
ostream& operator<<(ostream& outs, const Shunting_yard& sy){
    //for (int i=0; i<sy._size; i++){

        outs<< sy._postfix << endl;

    //}
    return outs;
}
