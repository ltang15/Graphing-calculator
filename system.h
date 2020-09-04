#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "graph.h"
#include "Graph_info.h"

using namespace std;
class System
{
public:
    System( Graph_info* info);
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& widnow);
private:

    sf::CircleShape shape;
    sf::Vector2f vel;
    Graph _g;
    Graph_info* _info;
};

#endif // SYSTEM_H
