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

    else if (checker == '4'){
        //cout << "********DRAW**********" << endl;
        setcolor(BLACK);
        circle(circle_x, circle_y, 30);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(circle_x, circle_y, BLACK);

        settextstyle(4, 4, 3);
        setcolor(RED);
        outtextxy(circle_x+5, circle_y+5, "K");
    }
    else if (checker == '8'){
        setcolor(LIGHTGRAY);
        circle(circle_x, circle_y, 30);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        floodfill(circle_x, circle_y, LIGHTGRAY);

        settextstyle(4, 4, 3);
        setcolor(RED);
        setbkcolor(LIGHTGRAY);
        outtextxy(circle_x+5, circle_y+5, "K");
    }
}
