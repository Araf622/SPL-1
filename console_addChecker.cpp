#include "header.h"

void console_addChecker(char checker_board[][8], int x, int y, char checker){
    checker_board[y][x] = checker;
}
