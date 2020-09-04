#include "graph.h"

Graph::Graph(Graph_info* info){
    _info = info;
    _plotter = Plot(info);

}
void Graph::update (){

    _points = _plotter();
}
void Graph::draw (sf::RenderWindow& window){

    sf::RectangleShape point(sf::Vector2f(2,2));
    point.setFillColor(sf::Color::Green);

    for (int i =0;i <_points.size(); i++){
        point.setPosition(_points[i]); // set position for item i from the _points
        window.draw(point);
    }


}
