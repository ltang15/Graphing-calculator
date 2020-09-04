/*
* Project: Graphing Calculator.
 * Purpose: To graph the input equation.
 *          Panning and zooming the graph.Clicking on the function history.
 *          Saving and displaying the equations from the previous run.
 * Notes: Inputting the equation frpm the console
 *

 */

#include <iostream>
#include "animate.h"

using namespace std;

int main()

{

    animate game;
    game.run();
    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;
    return 0;
}
