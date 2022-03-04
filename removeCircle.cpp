#include "header.h"

void remove_checker(int x, int y){
    int circle_x = 450 + x*80 + 40;
    int circle_y = 100 + y*80 + 40;

    circle(circle_x, circle_y, 30);


    setfillstyle(SOLID_FILL, WHITE);
    floodfill(circle_x, circle_y, WHITE);
}
