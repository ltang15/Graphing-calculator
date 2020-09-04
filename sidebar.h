#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Graph_info.h"

using namespace std;


class Sidebar
{
public:
    Sidebar(Graph_info* info);
    Sidebar(float left, float width);
    void load();
    void save();
    void update ();
    void draw(sf::RenderWindow& window);
    string& operator [](int index);

private:

    Graph_info* _info;
    sf::RectangleShape rect;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object

    float _left;
    float _width;

};

#endif // SIDEBAR_H
