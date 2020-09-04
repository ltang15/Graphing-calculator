#include "animate.h"
#include "constants.h"

#include <iostream>
#include "system.h"
#include "sidebar.h"
#include "string.h"
#include <string>
#include "vector"
#include "list"



using namespace std;



animate::animate(): _info(new Graph_info()),system (_info), sidebar(WORK_PANEL, SIDE_BAR)
{


    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will

    window.setFramerateLimit(60);

    mouseIn = true;




    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("../arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    myTextLabel = sf::Text("Graphing calculator", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color::White);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));



    //Creating axis
    x_axis = sf::RectangleShape(sf::Vector2f(WORK_PANEL , 1));
    y_axis = sf::RectangleShape(sf::Vector2f(1, SCREEN_HEIGHT));

    // color axis
    x_axis.setFillColor(sf::Color(80,80,80));
    y_axis.setFillColor(sf::Color(80,80,80));

    //set position for axis

    x_axis.setPosition(sf::Vector2f(0, _info->get_origin().y));
    y_axis.setPosition(sf::Vector2f(_info->get_origin().x,0));

    function.insert_head(_info->get_equation());

    //tell sidebar to load itself from file
     sidebar.load();

    //creating bounding rectangle for function history


     for(int i = 0; i < 10; i++){
         rectangle[i].setPosition(1033, 187+(23*i));
         rectangle[i].setSize(sf::Vector2f(70,23));

         rectangle[i].setFillColor(sf::Color::Transparent);
         rectangle[i].setOutlineColor(sf::Color::Transparent);
         rectangle[i].setOutlineThickness(1);
     }


    cout<<"animate instantiated successfully."<<endl;
}
animate::~animate(){
    //tell the sidebar to save itself
    //call function sidebar.save()

    sidebar.save();
    delete _info; //deallocate dynamic variable

}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);

    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);

    //. . . . . . . . . . . . . . . . . . .

    window.draw(this->x_axis);
    window.draw(this->y_axis);

    //input equation
    sidebar[SB_FUNCTION] = _info->get_equation();

    // display the domain
    sidebar[SB_DOMAIN - 1] = "Domain:";
    sidebar[SB_DOMAIN] ="(" + to_string(_info->get_domain().x) + ", " + to_string(_info->get_domain().y) + ")";

    //function history

    sidebar[SB_HISTORY - 1] = "Function history";

    // using the list to put the newest function on top
    // if we use vector.push_back, this will add the newest function at bottom

    List <string>::Iterator it = function.Begin();
    int i = 0;
    for (; it != function.End(); it++){

        sidebar[SB_HISTORY + i]= *it;
        i++;
    }



    for(int i = 0; i < 10; i++){
         window.draw (rectangle[i]);
    }

    window.draw (help_scr);
    window.draw (myMenu);

    for(int i = 0; i < 6; i++){
        window.draw(myText[i]);
    }



}

void animate::update(){
    //cause changes to the data for the next frame
    system.Step(command);
    command = 0;


    sidebar[SB_FUNCTION] = _info->get_equation();

    x_axis.setPosition(sf::Vector2f(0, _info->get_origin().y));
    y_axis.setPosition(sf::Vector2f(_info->get_origin().x,0));

    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION -1] = "Mouse position" + mouse_pos_string(window);



    }

}

void animate::render(){
       window.clear();
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;

   while (window.pollEvent(event))//or waitEvent
   {


       // check the type of the event...
        switch (event.type)
        {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){

                   case sf::Keyboard::Return:{

                      char exp [50];
                      cout << "f(x): ";
                      cin.getline(exp, 50, '\n');
                      _info->set_equation(exp);
                      string str = _info ->get_equation();

                     function.insert_head(str);

                      command = 0;
                      break;
                    }
                    case sf::Keyboard::Left:{
                       sidebar[SB_KEY_PRESSED] = "PAN LEFT";


                       _info -> pan_left();

                       command = 1;
                       break;
                    }
                   case sf::Keyboard::Right:{
                       sidebar[SB_KEY_PRESSED] = "PAN RIGHT";

                       _info -> pan_right();

                       command = 1;
                       break;
                   }
                   case sf::Keyboard::Up:{
                       sidebar[SB_KEY_PRESSED] = "PAN UP";

                       _info -> pan_up();

                       command = 2;
                       break;
                   }
                   case sf::Keyboard::Down:{
                       sidebar[SB_KEY_PRESSED] = "PAN DOWN";

                       _info -> pan_down();

                       command = 3;
                       break;
                   }


                   case sf::Keyboard::I :{
                       sidebar[SB_KEY_PRESSED] = "ZOOM IN";
                       _info->zoom_in();

                       command = 4;
                       break;
                   }
                   case sf::Keyboard::O :{
                       sidebar[SB_KEY_PRESSED] = "ZOOM OUT";
                       _info->zoom_out();

                       command = 5;
                       break;
                   }
                   case sf::Keyboard::R :{
                       sidebar[SB_KEY_PRESSED] = "RESET";
                       _info->set_domain(sf::Vector2f(MIN,MAX));
                       _info->set_range(sf::Vector2f(MIN,MAX));
                       _info -> set_origin(sf::Vector2f(WORK_PANEL/2,SCREEN_HEIGHT/2));

                       command = 6;
                       break;
                   }
                   case sf::Keyboard::M :{
                       help_scr.setPosition(310, 40);
                       help_scr.setSize(sf::Vector2f(400,210));

                       help_scr.setFillColor(sf::Color(50,50,50));
                       help_scr.setOutlineColor(sf::Color::Green);
                       help_scr.setOutlineThickness(3);

                       myMenu = sf::Text("MENU", font);
                       myMenu.setCharacterSize(20);
                       myMenu.setStyle(sf::Text::Bold);
                       myMenu.setFillColor(sf::Color::Green);
                       sf::FloatRect textRect = myMenu.getLocalBounds();
                       myMenu.setOrigin(textRect.left+ textRect.width/2.0f,
                                      textRect.top  + textRect.height/2.0f);

                       sf::FloatRect scrRect = help_scr.getLocalBounds();

                       myMenu.setPosition(sf::Vector2f(WORK_PANEL/2 ,scrRect.height/4.0f));

                       myText[0] = sf::Text("1. Press arrow to PAN UP, DOWN, LEFT, RIGHT.", font);
                       myText[1] = sf::Text("2. Press 'I' to ZOOM IN; 'O' to ZOOM OUT.", font);
                       myText[2] = sf::Text("3. Press 'Enter' to INPUT.", font);
                       myText[3] = sf::Text("4. Press 'R' to RESET the graph.", font);
                       myText[4] = sf::Text("5. Press 'M' to display the MENU.", font);

                       for (int i = 0; i < 5; i++){
                           myText[i].setCharacterSize(17);
                           myText[i].setStyle(sf::Text::Regular);
                           myText[i].setFillColor(sf::Color::White);
                           myText[i].setPosition(sf::Vector2f(320 ,scrRect.height/5.0f + 30*(i+1)));
                       }
                       myText[5] = sf::Text("'Backspace' to EXIT...", font);
                       myText[5].setCharacterSize(15);
                       myText[5].setStyle(sf::Text::Bold);
                       myText[5].setFillColor(sf::Color::Green);
                       myText[5].setPosition(sf::Vector2f(520 ,scrRect.height/5.0f + 180));


                       break;

                   }
                   case sf::Keyboard::BackSpace:{
                       help_scr.setSize(sf::Vector2f(0,0));// deleting the help box

                       //deleting the text
                       myMenu = sf::Text("", font);
                       for (int i = 0; i < 6; i++){
                           myText[i]= sf::Text("", font);
                       }

                       break;

                   }

                   case sf::Keyboard::Escape:{
                           sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                           window.close();
                        break;
                       }
                   default:
                        break;



           }
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:{
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
               break;
           }
           case sf::Event::MouseButtonReleased:{
                   if (event.mouseButton.button == sf::Mouse::Right){

//                       sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
//                               mouse_pos_string(window);

                   }

                   else{
//                       sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
//                               mouse_pos_string(window);


                       auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
                       auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates


                       List <string>::Iterator it = function.Begin();
                       Vector <string> list;

                       for (int i =0; it != function.End(); it++, i++){

                           list.push_back(*it);

                       }



                       for (int i = SB_FUNCTION; i < SB_FUNCTION+10; i++){
                            if(rectangle[i].getGlobalBounds().contains(translated_pos)){ // Rectangle-contains-point check
                           // Mouse is inside the rectangle

                                _info->set_equation(list[i]);

                            }
                       }
                   }
                   break;

           }
           default:
               break;
        }
   }
}
void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}







