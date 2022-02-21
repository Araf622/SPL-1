
#include "header.h"

void draw_checkerBoard()
{
    int i, j, k;
    int x = 450, y = 100;

    DWORD width = GetSystemMetrics(SM_CXSCREEN);
    DWORD height = GetSystemMetrics(SM_CYSCREEN);

    cout << height << endl;
    initwindow(width,height, "Checkers");

    for(int l = 0; l<8 ; l++){
        for(int i=0;i<8; i++){
            if((l+i)%2){
                setfillstyle(SOLID_FILL, RED);
                rectangle(x, y, x+80, y+80);
                floodfill(x+1, y+1, WHITE);

                /*circle(x+40, y-40, 20);
                setfillstyle(SOLID_FILL, BROWN);
                floodfill(x+40, y-40, BLACK);*/
            }
            else{
                setfillstyle(SOLID_FILL, WHITE);
                rectangle(x, y, x+80, y+80);
                floodfill(x+1, y+1, WHITE);
            }
            x+=80;
        }
        x=450;
        y+=80;
    }

    //checkers();

    getch();
}

