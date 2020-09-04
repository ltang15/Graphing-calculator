#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include "Graph_info.h"
#include "list.h"
#include "constants.h"
#include "Vector.h"

class animate{
public:
    animate();
    ~animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();

private:
    sf::RenderWindow window;

    sf::CircleShape mousePoint;         //The little red dot
    Graph_info* _info;
    System system;                      //container for all the animated objects
    List <string> function;

    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    sf::Text myMenu;
    sf::Text myText [6];
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar
    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;
    sf::RectangleShape rectangle [SB_HISTORY];
    sf::RectangleShape help_scr;

};

string mouse_pos_string(sf::RenderWindow& window);
string graph_domain(Graph_info* info);
void remove_space (string str);

#endif // GAME_H
