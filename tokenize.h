#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <iostream>
#include <cstring>
#include <queue.h>
#include "token.h"

using namespace std;

class Tokenize
{
public:
    Tokenize ();

    Queue <Token*> tokenize (string);


};

#endif // TOKENIZE_H
