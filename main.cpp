#include "header.h"

using namespace std;

char checker_board[8][8] = {'0'};

int main()
{
    //draw_checkerBoard(checker_board);
    checkerBoard(checker_board);
    draw_consoleCheckerBoard(checker_board);
    play(checker_board);
    return 0;
}
