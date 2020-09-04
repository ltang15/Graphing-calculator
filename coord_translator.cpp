#include "coord_translator.h"
#include "constants.h"

coord_translator::coord_translator(Graph_info* info){
    _info = info;
}

sf::Vector2f coord_translator::translator (sf::Vector2f point){

    //coords of the origin
    float x_origin = _info->get_origin().x;
    float y_origin = _info->get_origin().y;


    //coords of the graph
    float domain_min = _info->get_domain().x;
    float domain_max = _info->get_domain().y;
    float range_min  = _info->get_range().x;
    float range_max  = _info->get_range().y;


    float x_unit = WORK_PANEL/(domain_max - domain_min);
    float y_unit= SCREEN_HEIGHT/(range_max - range_min);




    sf::Vector2f screen;

    // translate coords
    screen.x = (point.x * x_unit) + x_origin;
    screen.y = -(point.y * y_unit) + y_origin;

    return screen ;
}
