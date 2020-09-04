#ifndef GRAPH_H
#define GRAPH_H
#include "Vector.h"
#include "plot.h"
#include <SFML/Graphics.hpp>
#include "Graph_info.h"

using namespace std;
class Graph
{
public:
    Graph(Graph_info* info);
    void update ();
    void draw (sf::RenderWindow &window);
private:
    Vector<sf::Vector2f> _points;
    Graph_info* _info;
    Plot _plotter;


};

#endif // GRAPH_H
