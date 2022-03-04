#include "header.h"

void add_checker(int x, int y){
    int circle_x = 450 + x*80 + 40;
    int circle_y = 100 + y*80 + 40;


    setcolor(BLACK);
    circle(circle_x, circle_y, 30);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(circle_x, circle_y, BLACK);


}
