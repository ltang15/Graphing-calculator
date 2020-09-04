#include "Graph_info.h"
#include "constants.h"
#include "coord_translator.h"

Graph_info::Graph_info (){
    _equation = "sin ( x )";
    _window_dimensions = sf::Vector2f (WORK_PANEL, SCREEN_HEIGHT);
    _origin = sf::Vector2f (WORK_PANEL/2, SCREEN_HEIGHT/2);
    _domain = sf::Vector2f (MIN, MAX);   // for the x-axis
    _range = sf::Vector2f (MIN, MAX);    // for the y-axis
    _points = POINTS;

}

Graph_info & Graph_info::operator =(const Graph_info& RHS){
    if(&RHS == this) return *this;

    _equation = RHS._equation;
    _window_dimensions = RHS._window_dimensions;
    _origin = RHS._origin;

    _domain = RHS._domain;
    _points = RHS._points;

    return *this;

}

Graph_info::Graph_info (const Graph_info& other){
    _equation = other._equation;
    _window_dimensions = other._window_dimensions;
    _origin = other._origin;

    _domain = other._domain;
    _points = other._points;

}

sf::Vector2f Graph_info::get_domain (){
    return _domain;
}

void Graph_info::set_domain (sf::Vector2f new_domain){

    _domain = new_domain;
}

sf::Vector2f Graph_info::get_range (){
    return _range;
}

void Graph_info::set_range (sf::Vector2f new_range){
    _range = new_range;
}

sf::Vector2f Graph_info::get_origin (){
    return _origin;
}

void Graph_info::set_origin (sf::Vector2f new_origin){

    _origin= new_origin;
}

string Graph_info::get_equation (){
    return _equation;
}

void Graph_info::set_equation (string equation){

    _equation = equation;
}

void Graph_info::zoom_in(){
    _domain.x -= _domain.x *0.25; //decrease domain 25%
    _domain.y -= _domain.y *0.25;

    _range.x -= _range.x *0.25; //decrease domain 25%
    _range.y -=  _range.y *0.25;




}

void Graph_info::zoom_out(){

    _domain.x += _domain.x *0.25; //increase domain 25%
    _domain.y += _domain.y *0.25;

    _range.x +=  _range.x *0.25; //increase domain 25%
    _range.y +=  _range.y *0.25;
}

void Graph_info::pan_left(){
    //decrease the domain by a pan_increment
    _domain.x -= PAN_INCREMENT;
    _domain.y -= PAN_INCREMENT;

    //increase the origin_x by a screen increment (based on pan_increment)
    // because origin is initialized by screen coord
    _origin.x += (PAN_INCREMENT* WORK_PANEL/(_domain.y - _domain.x));

}

void Graph_info::pan_right(){

     //increase the domain by a pan_increment
    _domain.x += PAN_INCREMENT;
    _domain.y += PAN_INCREMENT;

     //decrease the origin_x by a screen increment (based on pan_increment)
    _origin.x -= (PAN_INCREMENT* WORK_PANEL/(_domain.y - _domain.x));

}

void Graph_info::pan_up(){
     //decrease the range by a pan_increment
    _range.x -= PAN_INCREMENT;
    _range.y -= PAN_INCREMENT;

    //for pan up and pandown, the _origin.y changes
    _origin.y += (PAN_INCREMENT* WORK_PANEL/(_domain.y - _domain.x));



}
void Graph_info::pan_down(){
     //increase the range by a pan_increment

    _range.x += PAN_INCREMENT;
    _range.y += PAN_INCREMENT;
    _origin.y -= (PAN_INCREMENT* WORK_PANEL/(_domain.y - _domain.x));
}


