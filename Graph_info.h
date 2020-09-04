#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "string.h"

using namespace std;

struct Graph_info{
public:

    //big three
    Graph_info ();
    Graph_info & operator =(const Graph_info& RHS);
    Graph_info (const Graph_info& other);

    sf::Vector2f get_domain ();
    void set_domain (sf::Vector2f new_domain);

    sf::Vector2f get_range ();
    void set_range (sf::Vector2f new_range);


    sf::Vector2f get_origin ();
    void set_origin (sf::Vector2f new_origin);

    string get_equation();
    void set_equation (string equation);

    void zoom_in();
    void zoom_out();
    void pan_left();
    void pan_right();
    void pan_up();
    void pan_down();

private:
    string _equation;
    sf::Vector2f _window_dimensions;
    sf::Vector2f _origin;
    sf::Vector2f _domain;
    sf::Vector2f _range;

    int _points;

};

#endif // GRAPH_INFO_H
