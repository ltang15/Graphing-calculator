#include "plot.h"
#include "shunting_yard.h"
#include "rpn.h"
#include "coord_translator.h"
#include "variable.h"
#include "constants.h"
#include "function.h"
#include "LParent.h"
#include "RParent.h"
#include "number.h"
#include "operator.h"
#include "tokenize.h"

Plot::Plot(){}

Plot::Plot(Graph_info* info)
{
    _info = info;
}

Vector <sf::Vector2f> Plot::operator()(){

    Queue <Token*> infix;
    Tokenize token;
    infix = token.tokenize(_info->get_equation());

    Shunting_yard sy(infix, infix.size());

     _postfix = sy.postfix(); // infix -> postfix

    RPN rpn (_postfix); // postfix -> rpn

    Vector <sf::Vector2f> point;


    float domain_min = _info->get_domain().x;
    float domain_max = _info->get_domain().y;

    for (double x = domain_min; x <= domain_max; x+= INCREMENT){

        double y = rpn(x); // get the range for the corresponding x value
        sf::Vector2f p (x, y); // make a point

        coord_translator trans(_info);

        // translate into screen coords
        sf::Vector2f screen_p = trans.translator(p);

        point.push_back(screen_p); // push points into the vector
    }


    return point;
}
