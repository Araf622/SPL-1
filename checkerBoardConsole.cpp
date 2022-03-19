#include "header.h"

void checkerBoard(char checker_board[][8]){
    int i, j;

    for(i=0 ; i<=7; i++){
        for(j=0; j<=7; j++){
            if((i+j)%2 == 0){
                if(i <= 2)  checker_board[i][j] = '2';    // player 2's checkers
                else if(i>=5) checker_board[i][j] = '1';           // player 1's checkers
                else checker_board[i][j] = '0';
            }
        }
    }
}
void draw_consoleCheckerBoard(char checker_board[][8]){
    int i, j, k;

    int x = 450, y = 100;

    DWORD width = GetSystemMetrics(SM_CXSCREEN);
    DWORD height = GetSystemMetrics(SM_CYSCREEN);

    initwindow(width,height, "Checkers");
    setbkcolor(LIGHTBLUE);
    cleardevice();

        for(i = 0; i<8 ; i++){
        for(j=0;j<8; j++){
            if((i+j)%2 == 0){
                //Draw red boards
                setcolor(BLACK);
                rectangle(x, y, x+80, y+80);    //width 80, height 80
                setfillstyle(SOLID_FILL, RED);
                floodfill(x+1, y+1, BLACK);

                // ... Draw Player 1 Checkers (Black) .....
                if(checker_board[i][j] == '1'){
                    setcolor(BLACK);
                    circle(x+40, y+40, 30);
                    setfillstyle(SOLID_FILL, BLACK);
                    floodfill(x+40, y+40, BLACK);
                }

                 // ... Draw Player 2 Checkers (LightGray) .....
                else if(checker_board[i][j] == '2'){
                    setcolor(LIGHTGRAY);
                    circle(x+40, y+40, 30);
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    floodfill(x+40, y+40, LIGHTGRAY);
                }

            }
            else{
                //DRAW WHITE BOARDS
                setcolor(BLACK);
                rectangle(x, y, x+80, y+80);
                setfillstyle(SOLID_FILL, WHITE);
                floodfill(x+1, y+1, BLACK);
            }
            x+=80;
        }
        x=450;
        y+=80;
    }
    //play(checker_board);

    /*cout << endl << endl;

    cout << "\t\t\t\t";
    cout << "    ";
    for(k=0; k<8;k++)  cout << k << "   ";
    cout<<endl<<endl;

    for(i=0; i<8; i++){
        cout << "\t\t\t\t";
        cout << i << "  ";
        for(j=0; j<8; j++){
           if(checker_board[i][j] == '1') cout << "_1_|";
           else if (checker_board[i][j] == '2')   cout << "_2_|";
           else cout << "_ _|";
        }
        cout << endl;
    }
    cout << endl << endl;*/
}

