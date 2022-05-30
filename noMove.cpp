#include "header.h"

bool no_move(char checker_board[][8] ,char checker){
    int i, j;   // ** loop variable ****
    int x, y;    // ** condition check variable ****

    if(checker == '1'){
        for(i=7; i>=0; i--){
            for(j=0; j<=7; j++){
                if(checker_board[i][j] == '1'){

                    // ****** CHECKS UPPER RIGHT MOVE ******
                    if(((i-1)>=0 && (i-1) <=7) && ((j+1)>=0 && (j+1)<=7)){
                        if(checker_board[i-1][j+1] == '0')  return true;
                    }

                    // ******* CHECKS UPPER LEFT MOVE ****
                    if(((i-1)>=0 && (i-1) <=7) && ((j-1)>=0 && (j-1)<=7)){
                        if(checker_board[i-1][j-1] == '0')  return true;
                    }


                    // ** CHECK KILL FOR UPPER RIGHT CHECKER ****
                    if(checkKill(checker_board, j, i, 2, -2, '1'))   return true;


                    // *** CHECK KILL FOR UPPER RIGHT CHECKER ***
                    if(checkKill(checker_board, j, i, -2, -2, '1'))   return true;

                }
            }
        }
    }
    else if(checker == '2'){
        for(i=0; i<=7; i++){
            for(int j=0; j<=7; j++){
                if(checker_board[i][j] == '2'){

                    // ****** CHECKS LOWER RIGHT MOVE ******
                    if(((i+1)>=0 && (i+1) <=7) && ((j+1)>=0 && (j+1)<=7)){
                        if(checker_board[i+1][j+1] == '0')  return true;
                    }


                    // ******* CHECKS LOWER LEFT MOVE ****
                    if(((i+1)>=0 && (i+1) <=7) && ((j-1)>=0 && (j-1)<=7)){
                        if(checker_board[i+1][j-1] == '0')  return true;
                    }


                    // ** CHECK KILL FOR LOWER RIGHT CHECKER ****
                    if(checkKill(checker_board, j, i, 2, 2, '2') == true)   return true;


                    // *** CHECK KILL FOR UPPER RIGHT CHECKER ***
                    if(checkKill(checker_board, j, i, -2, 2, '2') == true)   return true;

                }
            }
        }
    }
    return false;
}
