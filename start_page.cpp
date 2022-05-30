#include "header.h"

void start(){
    char str0[] = "# The game is played on 8X8 squareboard";
    char str1[] = "# Each player has 12 checkers.";
    char str2[] = "# Checkers can make one diagonal jump";
    char str3[] = "# A checker can kill by taking a diagonal leap over opponent";
    char str4[] = "# A checker is upgraded to king if it reaches the furthest row";
    char str5[] = "# King checker can move both forward and backward";
    char str6[] = "# A player wins the game if the opponent has no checkers left";
    char str7[] = "  unable to make a move";

    DWORD width = GetSystemMetrics(SM_CXSCREEN);
    DWORD height = GetSystemMetrics(SM_CYSCREEN);

    initwindow(width,height, "Start");
    setbkcolor(LIGHTBLUE);
    cleardevice();

    settextstyle(10, 0, 6);
    setcolor(BLACK);
    outtextxy(560, 50, "CHECKERS GAME");


    settextstyle(4, 0, 4);
    setcolor(BLACK);
    outtextxy(560, 150, "       VS COM");
    setcolor(BLACK);
    rectangle(550,140, 950, 190);


    settextstyle(4, 0, 4);
    setcolor(BLACK);
    outtextxy(560, 220, "       2 Players");
    setcolor(BLACK);
    rectangle(550,210, 950, 260);

    settextstyle(10,HORIZ_DIR,4);
    setcolor(BLACK);
    outtextxy(450, 400, "Rules and Regulations:");

    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(450, 440, str0);

    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(450, 470, str1);

    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(450, 500, str2);

    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(450, 530, str3);

    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(450, 560, str4);

    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(450, 590, str5);

    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(450, 620, str6);

    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(450, 650, str7);





}
