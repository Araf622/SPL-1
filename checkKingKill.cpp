#include "header.h"

bool checkKingKill(char checker_board[][8],int source_x, int source_y, int diff_x, int diff_y, char checker){
    int x, y;

    if(diff_x == 2) x = source_x +1;
    else if(diff_x == -2) x = source_x - 1;

    if(diff_y == 2) y = source_y + 1;
    else if(diff_y == -2) y = source_y - 1;

     if(checker == '4'){
        if((checker_board[y][x] == '2' || checker_board[y][x] == '8') && checker_board[source_y+diff_y][source_x+diff_x] == '0'){
            if((source_y+diff_y >=0 && source_y+diff_y <=7) && (source_x+diff_x >=0 && source_x+diff_x<=7))
                return true;
        }
    }

    else if(checker == '8'){
        if((checker_board[y][x] == '1' || checker_board[y][x] == '4') && checker_board[source_y+diff_y][source_x+diff_x] == '0'){
            if((source_y+diff_y >=0 && source_y+diff_y <=7) && (source_x+diff_x >=0 && source_x+diff_x<=7))
                return true;
        }
    }
    return false;
}

