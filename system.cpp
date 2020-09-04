#include "system.h"
#include "random.h"

#include <iostream>

#include <constants.h>
System::System( Graph_info* info):_g(info), _info(info)
{


}


//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command){

        _g.update();


}


void System::Draw(sf::RenderWindow& window){
//    window.draw(shape);
   _g.draw(window);

}
