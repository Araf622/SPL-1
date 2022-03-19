#include "header.h"

int kill(char checker_board[][8],int source_x, int source_y, int diff_x, int diff_y, char checker){
    int x, y;

    if(diff_x == 2) x = source_x +1;
    else if(diff_x == -2) x = source_x - 1;

    if(diff_y == 2) y = source_y + 1;
    else if(diff_y == -2) y = source_y - 1;

    if(checker == '1'){
        if(checker_board[y][x] == '2' && checker_board[source_y+diff_y][source_x+diff_x] == '0'){
            checker_board[y][x] = '0';
            remove_checker(y,x);
            return 1;
        }
    }
    else if(checker == '2'){
        if(checker_board[y][x] == '1' && checker_board[source_y+diff_y][source_x+diff_x] == '0'){
            checker_board[y][x] = '0';
            remove_checker(y,x);
            return 1;
        }
    }
    return 0;
}
