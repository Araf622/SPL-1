#include "header.h"

using namespace std;

char checker_board[8][8] = {'0'};

int main()
{
    int mode;
    //draw_checkerBoard(checker_board);
    start();
    mode = select_mode();
    checkerBoard(checker_board);
    draw_consoleCheckerBoard(checker_board);

    if(mode ==1)
        multiplayer(checker_board);
    else if(mode ==2)
        play(checker_board);
    //getch();
}
