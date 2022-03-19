#include "header.h"

void add_checker(int y, int x, char checker){
    int circle_x = 450 + x*80 + 40;
    int circle_y = 100 + y*80 + 40;


    if(checker == '1'){
        setcolor(BLACK);
        circle(circle_x, circle_y, 30);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(circle_x, circle_y, BLACK);
    }

    else if(checker == '2'){
            setcolor(LIGHTGRAY);
            circle(circle_x, circle_y, 30);
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            floodfill(circle_x, circle_y, LIGHTGRAY);
    }

}
