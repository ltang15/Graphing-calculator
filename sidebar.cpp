#include "sidebar.h"
#include "constants.h"
#include "string.h"
#include <fstream>
using namespace std;

Sidebar::Sidebar(Graph_info* info){
    _info = info;

}

Sidebar::Sidebar(float left, float width):_left(left), _width(width){
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(50);

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(80,80,80)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(18);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color::White);

    ////this is how you would position text on screen:
    sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));


    //Fill the items vector with empty strings so that we can use [] to read them:


    for (int i=0 ; i<30; i++){

        items.push_back("");

    }




    cout<<"Sidebar: CTOR: Exit."<<endl;
}



void Sidebar::load(){
   string str = "";
   //5 steps to read from file

   //1.declare the input file
   ifstream ifs;

   //2. open the file
   ifs.open ("file.txt");

   //3.check for fail
   if(ifs.fail()){
       cout << "File does not exit" << endl;
       _info->set_equation("sin ( x )");
       exit(1);
   }

   //4. read. Using get line function since we have spaces in the string

    getline(ifs, str);
    //cout << "string: " << str << endl;

    while (!ifs.eof()){

        items.push_back(str);
        getline(ifs, str);

    }
    //5.close
    ifs.close();

}

void Sidebar::save(){
    cout<<"\n\n ------- save ------"<<endl;
    //5 steps to write into file

    //1.declare the output file
    ofstream ofs;

    //2. open the file
    ofs.open ("file.txt");

    //3.check for fail
    if(ofs.fail()){
        cout << "Unable to write into file. Exiting." << endl;

        exit(1);
    }

    //4. Write

    for (int i =SB_HISTORY; i < items.size(); i++){
        ofs << items [i] << endl;

    }
     //5.close
     ofs.close();


}

void Sidebar::draw(sf::RenderWindow& window){
    const double VERTICAL_LINE_SPACING = 7.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    float height = 10;

    for (vector<string>::iterator it = items.begin();
                                it!= items.end(); it++){
        bool blank = false;
        if (strlen(it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else{
            sb_text.setString(it->c_str());
        }
        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING - 5;
        if (!blank)
            window.draw(sb_text);
    }


}

string& Sidebar::operator [](int index){
    return items[index];
}
