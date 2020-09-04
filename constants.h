#ifndef CONSTANTS_H
#define CONSTANTS_H
const float SCREEN_WIDTH = 1280;
const float SCREEN_HEIGHT = 720;
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;

//domain
const float MIN = -5;
const float MAX = 5;


const float POINTS = 1000;
const double INCREMENT = (MAX - MIN)/POINTS;

const double PAN_INCREMENT = 1.0f;

const int SB_FUNCTION = 0;
const int SB_DOMAIN = SB_FUNCTION + 3;
const int SB_HISTORY = 10;





const int SB_MOUSE_POSITION = SB_DOMAIN + 3;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED;
#endif // CONSTANTS_H
