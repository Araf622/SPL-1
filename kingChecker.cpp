#include "header.h"

bool kingMove(int source_y, int source_x, int dest_y, int dest_x, char checker_board[][8], char checker){
    int diff_x = dest_x - source_x;
    int diff_y = dest_y - source_y;
    bool flag = true;

    // ***** CHECKS IF MOVE IS OKAY *****
        if((diff_x == diff_y) || (diff_x == -diff_y)){
            if(diff_x > 0){
                if(diff_y > 0){
                    for(int i = 1; i <= diff_x; i++){
                        if(checker_board[source_y+i][source_x+i] != '0'){
                            flag = false;
                            break;
                        }
                    }
                }
                else if(diff_y < 0){
                    for(int i = 1; i <= diff_x; i++){
                        if(checker_board[source_y-i][source_x+i] != '0'){
                            flag = false;
                            break;
                        }
                    }
                }
            }

            else if(diff_x < 0){
                if(diff_y > 0){
                    for(int i = 1; i <= -diff_x; i++){
                        if(checker_board[source_y+i][source_x-i] != '0'){
                            flag = false;
                            break;
                        }
                    }
                }
                else if(diff_y < 0){
                    for(int i = 1; i <= -diff_x; i++){
                        if(checker_board[source_y-i][source_x-i] != '0'){
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }

        else {
            return false;
        }




    return flag;
}
