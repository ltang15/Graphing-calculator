#include "tokenize.h"
#include "number.h"
#include "Vector.h"
#include "string.h"
#include "ctype.h"
#include "function.h"
#include "variable.h"
#include "operator.h"
#include "LParent.h"
#include "RParent.h"
#include <sstream>


Tokenize::Tokenize (){


}


Queue <Token*> Tokenize::tokenize (string equation){

    Queue <Token*> tokenized;

    stringstream str; //
    string token;
    str << equation;

    Vector <string> token_list;

   //getting the string token one by one
   //input: x + 2.0 * 3.0
   //vector: x|+|2.0|*|3.0
    while (str >> token){

       token_list.push_back (token); // push into vector string

    }




    //using isdigit to check for number
    //stod (convert string to double)
    //stoi (convert string to int)

    while (!token_list.empty()){
        string list = "";

        list += token_list.front();         // since vector pop the last element, so we cann't use the pop() here
        token_list.erase(0);                // call the front ekement then erase it

        if(isdigit(list.front())){    //check if first element of the string list is a number

            if (list.find('.') == -1){ //didn't find '.', so it's an integer
                int num = stoi(list);
                Token* integer = new Number (num);
                tokenized.push(integer);
            }
            else{

                //double number case
                double d = stod(list);
                Token* doub = new Number (d);
                tokenized.push(doub);

            }
         }

        else if (isalpha(list.front())){ // check for variable and function
            if (list == "x"){
                Token* var = new Variable();
                tokenized.push (var);


            }
            else if (list == "sin" || list == "cos" || list =="tan" || list =="log"|| list =="abs"|| list =="sqrt"|| list =="exp"){
               Token* func = new Function (list);
               tokenized.push (func);

            }


        }
        else if (list == "("){ // left Parent
            Token* left = new LParent();
            tokenized.push (left);

        }
        else if (list == ")"){ //right Parent
            Token* right = new RParent();
            tokenized.push (right);

        }
        else{ // operator case
            Token* op = new Operator(list);
            tokenized.push(op);
        }

    }
       return tokenized ;
}
