#include "header.h"

void start(){
    DWORD width = GetSystemMetrics(SM_CXSCREEN);
    DWORD height = GetSystemMetrics(SM_CYSCREEN);

    initwindow(width,height, "Start");
    setbkcolor(LIGHTBLUE);
    cleardevice();

    settextstyle(1, 0, 4);
    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(560, 310, "       VS COM");

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    rectangle(550,300, 950, 350);
    floodfill(551, 301, WHITE);


    settextstyle(1, 0, 4);
    setcolor(WHITE);
    outtextxy(560, 380, "       2 Players");

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    rectangle(550,370, 950, 420);
    floodfill(551, 371, WHITE);
}
