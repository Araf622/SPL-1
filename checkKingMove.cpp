#include "header.h"

bool checkKingMove(char checker_board[][8] ,char checker){
    int i, j;   // ** loop variable ****
    int x, y;    // ** condition check variable ****

    if(checker == '4'){
        for(i=7; i>=0; i--){
            for(j=0; j<=7; j++){
                if(checker_board[i][j] == '4'){

                    // ****** CHECKS UPPER RIGHT MOVE ******
                    if(((i-1)>=0 && (i-1) <=7) && ((j+1)>=0 && (j+1)<=7)){
                        if(checker_board[i-1][j+1] == '0')  return true;
                    }


                    // ******* CHECKS UPPER LEFT MOVE ****
                    if(((i-1)>=0 && (i-1) <=7) && ((j-1)>=0 && (j-1)<=7)){
                        if(checker_board[i-1][j-1] == '0')  return true;
                    }


                     // ****** CHECKS LOWER RIGHT MOVE ******
                    if(((i+1)>=0 && (i+1) <=7) && ((j+1)>=0 && (j+1)<=7)){
                        if(checker_board[i+1][j+1] == '0')  return true;
                    }


                    // ******* CHECKS LOWER LEFT MOVE ****
                    if(((i+1)>=0 && (i+1) <=7) && ((j-1)>=0 && (j-1)<=7)){
                        if(checker_board[i+1][j-1] == '0')  return true;
                    }


                    // ** CHECK KILL FOR UPPER RIGHT CHECKER ****
                    if(checkKingKill(checker_board, j, i, 2, -2, '4'))   return true;


                    // *** CHECK KILL FOR UPPER RIGHT CHECKER ***
                    if(checkKingKill(checker_board, j, i, -2, -2, '4'))   return true;


                    // ** CHECK KILL FOR LOWER RIGHT CHECKER ****
                    if(checkKingKill(checker_board, j, i, 2, 2, '4'))   return true;


                    // *** CHECK KILL FOR UPPER RIGHT CHECKER ***
                    if(checkKingKill(checker_board, j, i, -2, 2, '4'))   return true;

                }


            }
        }
    }
    else if(checker == '8'){
        for(i=0; i<=7; i++){
            for(int j=0; j<=7; j++){
                if(checker_board[i][j] == '8'){

                    // ****** CHECKS UPPER RIGHT MOVE ******
                    if(((i-1)>=0 && (i-1) <=7) && ((j+1)>=0 && (j+1)<=7)){
                        if(checker_board[i-1][j+1] == '0')  return true;
                    }


                    // ******* CHECKS UPPER LEFT MOVE ****
                    if(((i-1)>=0 && (i-1) <=7) && ((j-1)>=0 && (j-1)<=7)){
                        if(checker_board[i-1][j-1] == '0')  return true;
                    }


                    // ****** CHECKS LOWER RIGHT MOVE ******
                    if(((i+1)>=0 && (i+1) <=7) && ((j+1)>=0 && (j+1)<=7)){
                        if(checker_board[i+1][j+1] == '0')  return true;
                    }


                    // ******* CHECKS LOWER LEFT MOVE ****
                    if(((i+1)>=0 && (i+1) <=7) && ((j-1)>=0 && (j-1)<=7)){
                        if(checker_board[i+1][j-1] == '0')  return true;
                    }


                    // ** CHECK KILL FOR UPPER RIGHT CHECKER ****
                    if(checkKingKill(checker_board, j, i, 2, -2, '8'))   return true;


                    // *** CHECK KILL FOR UPPER LEFT CHECKER ***
                    if(checkKingKill(checker_board, j, i, -2, -2, '8'))   return true;


                    // ** CHECK KILL FOR LOWER RIGHT CHECKER ****
                    if(checkKingKill(checker_board, j, i, 2, 2, '8'))   return true;


                    // *** CHECK KILL FOR UPPER LEFT CHECKER ***
                    if(checkKingKill(checker_board, j, i, -2, 2, '8'))   return true;

                }
            }
        }
    }

    return false;
}


