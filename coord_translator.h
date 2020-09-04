#ifndef COORD_TRANSLATOR_H
#define COORD_TRANSLATOR_H
#include "Vector.h"
#include <SFML/Graphics.hpp>
#include "Graph_info.h"

class coord_translator
{
public:
   coord_translator(Graph_info* info);
   sf::Vector2f translator (sf::Vector2f point);

private:
    Graph_info* _info;
};

#endif // COORD_TRANSLATOR_H
