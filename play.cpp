#include "header.h"

void play(char checker_board[][8]){
    int move_selector = 0;      // to identify movement
    int player_selector = 1;    // to identify player
    int source_x, source_y;     // from which position to select
    int dest_x, dest_y;         // to which position to go
    int is_kill;
    int p1_checkers = 12;       // no of PLAYER 1 checkers
    int p2_checkers = 12;       // no of PLAYER 2 checkers
    POINT cursor;
    bool check_move = true;
    //int i, j;
    bool flag = true;

    while(1){

        while(flag){
            // ******** PLAYER 1 **********
            if(player_selector%2){

                 // ********CHECKS WIN CONDITION (NO CHECKERS) *****
                no_checkers(p2_checkers, '1');
                no_checkers(p1_checkers, '2');

                //  ********CHECKS WIN CONDITION (NO MOVE) *****
                check_move = no_move(checker_board ,'1');
                if(check_move == false){
                    cout << "\t\t\t\t" << "PLAYER 2 WON!!" << endl;
                    exit(0);
                }

                cout << "\t\t\t\t" << "Player 1's move: " <<endl;

                // ask for checker until right position is entered
                while(1){
                    // ... INPUT CHECKER POSTION
                    cout << "\t\t\t\t" << "Select checker : ";
                    cin >> source_y >> source_x;


                    //cout << "checker : " << checker_board[source_y][source_x]<<endl;

                    //checks validity -----Normal Or King checker
                    if((checker_board[source_y][source_x] == '1' || checker_board[source_x][source_y] == '100') && (source_y >=0 && source_y <=7) && (source_x>=0 && source_x<=7)){
                        //move_selector++;
                        break;
                    }
                    else    cout << "\t\t\t\t" << "Wrong selection!" << endl;
                }

                // ask for destination until right one is entered
                while(1){
                    cout << "\t\t\t\tSelect destination : ";
                    cin >> dest_y >> dest_x;

                    int diff_x = dest_x - source_x;
                    int diff_y = dest_y - source_y;

                    /////**********KING*********
                    if(checker_board[source_y][source_x] == '100'){
                        if(((dest_x>=0 && dest_x <=7) && (dest_y >= 0 && dest_y <=7)) && checker_board[dest_y][dest_x] == '0'){

                        }
                    }

                    else{
                        //checks if entered value is in range
                        if((dest_x>=0 && dest_x <=7) && (dest_y >= 0 && dest_y <=7)){

                            // checks if there is any checker in that postion
                            if(checker_board[dest_y][dest_x] == '0'){
                                //checks if the move is valid
                                if((diff_x == -1 || diff_x == 1) && (diff_y == -1)){
                                    console_removeChecker(checker_board,source_x, source_y);

                                    console_addChecker(checker_board, dest_x, dest_y, '1');
                                    system("cls");
                                    draw_consoleCheckerBoard(checker_board);
                                    player_selector++;
                                    break;
                                }

                                // ******* PLAYER 1 KILL *********
                                else if((diff_x == -2 || diff_x == 2) && (diff_y == -2)){
                                    is_kill = kill(checker_board, source_x, source_y, diff_x, diff_y, '1');

                                    if(!is_kill){
                                        cout << "\t\t\t\t" << "Wrong move"<<endl;
                                        break;
                                    }
                                    p2_checkers--;
                                    console_removeChecker(checker_board, source_x, source_y);
                                    console_addChecker(checker_board, dest_x, dest_y,'1');
                                    system("cls");
                                    draw_consoleCheckerBoard(checker_board);
                                    break;
                                }

                                else {
                                    cout << "\t\t\t\t" << "Wrong move!" << endl;
                                    break;
                                }
                            }
                            else{
                                 cout << "\t\t\t\t" << "Wrong move!" << endl;
                                 break;
                            }
                        }
                        else{
                            cout << "Wrong move!" << endl;
                            break;
                        }
                    }
                 }

            }

            //***** PLAYER 2 ***********
            else{

                // *******CHECKS WIN CONDITION (NO MOVE) ********
                check_move = no_move(checker_board ,'2');
                if(check_move == false){
                    cout << "\t\t\t\t" << "PLAYER 1 WON!!" << endl;
                    exit(0);
                }

                // ******** CHECKS WIN CONDITION (NO CHECKERS) *****
                no_checkers(p1_checkers, '2');
                no_checkers(p2_checkers, '1');

                cout << "\t\t\t\t" << "Player 2's move: " <<endl;

                // ask for checker until right position is entered
                while(1){
                    cout << "\t\t\t\t" << "Select checker : ";
                    cin >> source_y >> source_x;    //matrix input

                    //checks validity
                    if((checker_board[source_y][source_x] == '2' || checker_board[source_x][source_y] == '200') && (source_x >=0 && source_y <=7)){
                        move_selector++;
                        break;
                    }
                    else    cout << "\t\t\t\t" << "Wrong selection!" << endl;
                }

                // ask for destination until right one is entered
                while(1){
                    cout << "\t\t\t\t" << "Select destination : ";
                    cin >> dest_y >> dest_x;

                    int diff_x = dest_x - source_x;
                    int diff_y = dest_y - source_y;


                    if(checker_board[source_x][source_y] == '200'){

                    }

                    else{
                        //checks if entered value is in range
                        if((dest_x>=0 && dest_x <=7) && (dest_y >= 0 && dest_y <=7)){

                            // checks if there is any checker in that postion
                            if(checker_board[dest_y][dest_x] == '0'){
                                //checks if the move is valid
                                if((diff_x == -1 || diff_x == 1) && (diff_y == 1)){
                                    //move
                                    console_removeChecker(checker_board,source_x, source_y);
                                    console_addChecker(checker_board, dest_x, dest_y, '2');
                                    system("cls");
                                    draw_consoleCheckerBoard(checker_board);
                                    player_selector++;
                                    break;
                                }

                                // ******* PLAYER 2 KILL *********
                                else if((diff_x == -2 || diff_x == 2) && (diff_y == 2)){
                                    is_kill = kill(checker_board, source_x, source_y, diff_x, diff_y, '2');
                                    if(!is_kill){
                                        cout << "\t\t\t\t" << "Wrong move!"<<endl;
                                        break;
                                    }
                                    p1_checkers--;
                                    console_removeChecker(checker_board, source_x, source_y);
                                    console_addChecker(checker_board, dest_x, dest_y,'2');
                                    system("cls");
                                    draw_consoleCheckerBoard(checker_board);
                                    break;
                                }

                                else{
                                    cout << "\t\t\t\t" << "Wrong move!" << endl;
                                    break;
                                }
                            }
                            else{
                                 cout << "\t\t\t\t" << "Wrong move!" << endl;
                                 break;
                            }
                        }
                        else{
                            cout << "\t\t\t\t" << "Wrong move!" << endl;
                            break;
                        }
                    }
                 }

            }
            cout << endl;
            //-------
        }

    }
}
