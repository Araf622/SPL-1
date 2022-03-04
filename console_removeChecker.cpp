#include "header.h"

void console_removeChecker(char checker_board[][8], int x, int y){
    checker_board[y][x] = '0';
}
