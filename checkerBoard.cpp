#include "header.h"

void draw_checkerBoard(char checker_board[][8])
{
    int i, j;
    int x = 450, y = 100;

    DWORD width = GetSystemMetrics(SM_CXSCREEN);
    DWORD height = GetSystemMetrics(SM_CYSCREEN);

    initwindow(width,height, "Checkers");

    for(i = 0; i<8 ; i++){
        for(j=0;j<8; j++){
            if((i+j)%2){
                //Draw red boards
                setfillstyle(SOLID_FILL, RED);
                setcolor(WHITE);
                rectangle(x, y, x+80, y+80);    //width 80, height 80
                floodfill(x+1, y+1, WHITE);

            }
            else{
                //DRAW WHITE BOARDS
                setfillstyle(SOLID_FILL, WHITE);
                setcolor(WHITE);
                rectangle(x, y, x+80, y+80);
                floodfill(x+1, y+1, WHITE);

                //DRAW CIRCLES
                if(i>4){
                    setcolor(BLACK);
                    circle(x+40, y+40, 30);     // radius 30
                    setfillstyle(SOLID_FILL, BLACK);
                    floodfill(x+40, y+40, BLACK);
                    checker_board[i][j] = 1;
                }

                else if(i<3){
                    setcolor(BLUE);
                    circle(x+40, y+40, 30);
                    setfillstyle(SOLID_FILL, BLUE);
                    floodfill(x+40, y+40, BLUE);
                    checker_board[i][j] = 1;
                }
            }
            x+=80;
        }
        x=450;
        y+=80;
    }

    move_checkers(checker_board);
    getch();
}

