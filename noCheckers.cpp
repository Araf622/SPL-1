#include "header.h"

bool no_checkers(char checker_board[][8],int n, char checker){
    if(!n){
        /*cout << endl << endl;
        setcolor(BLACK);
        rectangle(50,100, 440, 260);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        floodfill(51, 101, BLACK);*/
        draw_consoleCheckerBoard(checker_board);
        if(checker == '1') {
            //cout << "\t\t\t" << "PLAYER 1 WON!!" << endl;
            settextstyle(10, 4, 4);
            setcolor(WHITE);
            setbkcolor(BLACK);
            outtextxy(400, 450, "PLAYER 1 WON!!");
        }
        else if(checker == '2'){
            cout << "\t\t\t" << "PLAYER 2 WON!!" << endl;
            settextstyle(10, 4, 4);
            setcolor(WHITE);
            setbkcolor(BLACK);
            outtextxy(400, 450, "PLAYER 2 WON!!");
        }
        /*setcolor(LIGHTBLUE);
        rectangle(50,100, 440, 260);*/
        getch();
        return false;
    }

    else
        return true;

}
