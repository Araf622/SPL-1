#include "header.h"

void remove_checker(int y, int x){
    int circle_x = 450 + x*80 + 40;
    int circle_y = 100 + y*80 + 40;

    setcolor(RED);
    circle(circle_x, circle_y, 30);
    setfillstyle(SOLID_FILL, RED);
    floodfill(circle_x, circle_y, RED);
}
