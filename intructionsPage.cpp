#include "header.h"

void drawInstructions(){
    DWORD width = GetSystemMetrics(SM_CXSCREEN);
    DWORD height = GetSystemMetrics(SM_CYSCREEN);

    initwindow(width,height, "Instructions");
    setbkcolor(LIGHTBLUE);
    cleardevice();

    setcolor(BLACK);
    rectangle(400, 100, 1000, 900);    //width 80, height 80
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(401, 101, BLACK);


    getch();

    /*setcolor(BLACK);
    rectangle(x, y, x+80, y+80);    //width 80, height 80
    setfillstyle(SOLID_FILL, RED);
    floodfill(x+1, y+1, BLACK);*/
}
