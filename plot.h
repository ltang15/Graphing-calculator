#ifndef PLOT_H
#define PLOT_H

#include "Vector.h"
#include <SFML/Graphics.hpp>
#include "Graph_info.h"
#include "queue.h"
#include "token.h"

class Plot
{
public:

    Plot();
    Plot(Graph_info* inf0);
    Vector <sf::Vector2f> operator()();// returning the vector holding screen coords
private:
    Graph_info* _info;
    Queue <Token*> _postfix;

};

#endif // PLOT_H
