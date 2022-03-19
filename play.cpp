#include "header.h"

void play(char checker_board[][8]){
    int move_selector = 0;      // to identify movement
    int player_selector = 1;    // to identify player
    int source_x, source_y;     // from which position to select
    int dest_x, dest_y;         // to which position to go
    int is_kill;
    int p1_checkers = 12;       // no of PLAYER 1 checkers
    int p2_checkers = 12;       // no of PLAYER 2 checkers
    int cur_x, cur_y;
    POINT cursor;
    int click[2];
    bool check_move = true;
    //int i, j;
    bool flag = true;

    while(1){

        while(1){
            source_x = 100, source_y =100;
            dest_x = 100, dest_y = 100;

            // ******** PLAYER 1 **********
            if(player_selector%2){
                //REMOVE PLAYER 2 MENU
                setcolor(LIGHTBLUE);
                rectangle(0,0, 430, 400);
                setfillstyle(SOLID_FILL, LIGHTBLUE);
                floodfill(1, 1, LIGHTBLUE);

                //  ********CHECKS WIN CONDITION (NO MOVE) *****
                check_move = no_move(checker_board ,'1');
                if(check_move == false){
                    cout << "\t\t\t" << "PLAYER 2 WON!!" << endl;
                    // *** SHOW RESULT IN GRAPHICS ****
                    settextstyle(3, 4, 4);
                    setcolor(WHITE);
                    setbkcolor(BLACK);
                    outtextxy(400, 340, "Player 2 WON!!");
                }

                // ********CHECKS WIN CONDITION (NO CHECKERS) *****
                no_checkers(p2_checkers, '1');

                /* SHOW PLAYER IN GRAPHICS WINDOW */
                cout << "Player 1's move: " <<endl;
                settextstyle(3, 4, 4);
                setcolor(WHITE);
                setbkcolor(BLACK);
                outtextxy(400, 200, "Player 1's move");

                // ask for checker until right position is entered
                while(1){
                    //  ......SELECT CHECKER .........
                    // ****INPUT IN GRAPHICS **
                    cout << "Select checker : ";
                    settextstyle(3, 4, 3);
                    setcolor(WHITE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "    Select Checker");

                    //cin >> source_y >> source_x;    // matrix input*/

                    get_source_click(click);
                    //cout << endl;
                    //cout << "Check" << endl;
                    //cout << click[0] << " " << click[1]<< endl;
                    source_y = find_y_position(click[0]);
                    source_x = find_x_position(click[1]);
                    //cout << source_y << " " << source_x<< endl;
                   //checks validity -----Normal Or King checker
                    if((checker_board[source_y][source_x] == '1' || checker_board[source_x][source_y] == '100') && (source_y >=0 && source_y <=7) && (source_x>=0 && source_x<=7)){
                        move_selector++;
                        break;
                    }
                    else    cout << "\t\t\t\t" << "Wrong selection!" << endl;
                    delay(600);
                }
                // ask for destination until right one is entered
                while(1){
                    //remove Player 1 Select Checker menu
                    setcolor(LIGHTBLUE);
                    setfillstyle(SOLID_FILL, LIGHTBLUE);
                    rectangle(400,250, 450, 300);
                    floodfill(401, 251, LIGHTBLUE);

                    // ... SELECT DESTINATION ......
                    cout << "Select destination : ";

                    settextstyle(3, 4, 3);
                    setcolor(WHITE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "Select Desination");
                    //cin >> dest_y >> dest_x;*/

                    get_destination_click(click);


                    dest_y = find_y_position(click[0]);
                    dest_x = find_x_position(click[1]);

                    /*cout << click[0] << " " << click[1] << endl;
                    cout << dest_y << " " << dest_x << endl;*/
                    int diff_x = dest_x - source_x;
                    int diff_y = dest_y - source_y;

                            //checks if entered value is in range
                            if((dest_x>=0 && dest_x <=7) && (dest_y >= 0 && dest_y <=7)){

                                // checks if there is any checker in that postion
                                if(checker_board[dest_y][dest_x] == '0'){
                                    //checks if the move is valid
                                    if((diff_x == -1 || diff_x == 1) && (diff_y == -1)){
                                        //move
                                        console_removeChecker(checker_board,source_x, source_y);
                                        remove_checker(source_y, source_x);

                                        console_addChecker(checker_board, dest_x, dest_y, '1');
                                        add_checker(dest_y, dest_x, '1');

                                        //cout << "tst" <<endl;

                                        //system("cls");
                                        //cleardevice();
                                        //draw_consoleCheckerBoard(checker_board);
                                        player_selector++;
                                        break;
                                    }

                                    // ******* PLAYER 1 KILL *********
                                    else if((diff_x == -2 || diff_x == 2) && (diff_y == -2)){
                                        is_kill = kill(checker_board, source_x, source_y, diff_x, diff_y, '1');

                                        if(!is_kill){
                                            cout << "Wrong move"<<endl;
                                            break;
                                        }
                                        p2_checkers--;
                                        console_removeChecker(checker_board, source_x, source_y);
                                        remove_checker(source_y, source_x);

                                        console_addChecker(checker_board, dest_x, dest_y,'1');
                                        add_checker(dest_y, dest_x, '1');


                                        //system("cls");
                                        //cleardevice();
                                        //draw_consoleCheckerBoard(checker_board);
                                        break;
                                    }

                                    else {
                                        cout << "Wrong move!" << endl;
                                        break;
                                    }
                                }
                                else{
                                     cout << "Wrong move!" << endl;
                                     break;
                                }
                            }
                            else{
                                cout << "Wrong move!" << endl;
                                break;
                            }
                            delay(600);
                        }

            }

            //***** PLAYER 2 ***********
            else{
                //remove Player 1 Menu
                setcolor(LIGHTBLUE);
                setfillstyle(SOLID_FILL, LIGHTBLUE);
                rectangle(400,200, 450, 300);
                floodfill(401, 201, LIGHTBLUE);

                // *******CHECKS WIN CONDITION (NO MOVE) ********
                check_move = no_move(checker_board ,'2');
                if(check_move == false){
                    cout << "\t\t\t" << "PLAYER 1 WON!!" << endl;
                    settextstyle(3, 4, 4);
                    setcolor(WHITE);
                    setbkcolor(BLACK);
                    outtextxy(400, 340, "Player 1 WON!!");
                }

                // ******** CHECKS WIN CONDITION (NO CHECKERS) *****
                no_checkers(p1_checkers, '2');

                cout << "Player 2's move: " <<endl;
                settextstyle(3, 4, 4);
                setcolor(WHITE);
                setbkcolor(BLACK);
                outtextxy(400, 200, "Player 2's move");

                // ask for checker until right position is entered
                while(1){

                    cout << "Select checker : ";
                    settextstyle(3, 4, 3);
                    setcolor(WHITE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "    Select Checker");

                    //cin >> source_y >> source_x;    //matrix input
                    get_source_click(click);
                    source_y = find_y_position(click[0]);
                    source_x = find_x_position(click[1]);


                    //checks validity
                    if(checker_board[source_y][source_x] == '2' && (source_x >=0 && source_y <=7)){
                            move_selector++;
                            break;
                    }
                    else    cout << "Wrong selection!" << endl;

                    delay(600);
                }

                // ask for destination until right one is entered
                while(1){

                    //remove PLAYER 2 SELECT CHECKER MENU
                    setcolor(LIGHTBLUE);
                    setfillstyle(SOLID_FILL, LIGHTBLUE);
                    rectangle(400,250, 450, 300);
                    floodfill(401, 251, LIGHTBLUE);

                    cout << "Select destination : ";
                    settextstyle(3, 4, 3);
                    setcolor(WHITE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "Select Destination");
                    //cin >> dest_y >> dest_x;

                    get_destination_click(click);


                    dest_y = find_y_position(click[0]);
                    dest_x = find_x_position(click[1]);

                            int diff_x = dest_x - source_x;
                            int diff_y = dest_y - source_y;

                            //checks if entered value is in range
                            if((dest_x>=0 && dest_x <=7) && (dest_y >= 0 && dest_y <=7)){

                                // checks if there is any checker in that postion
                                if(checker_board[dest_y][dest_x] == '0'){
                                    //checks if the move is valid
                                    if((diff_x == -1 || diff_x == 1) && (diff_y == 1)){
                                        //move
                                        console_removeChecker(checker_board,source_x, source_y);
                                        remove_checker(source_y, source_x);

                                        console_addChecker(checker_board, dest_x, dest_y, '2');
                                        add_checker(dest_y, dest_x, '2');
                                        //system("cls");
                                        //cleardevice();
                                        //draw_consoleCheckerBoard(checker_board);
                                        player_selector++;
                                        break;
                                    }

                                    // ******* PLAYER 2 KILL *********
                                    else if((diff_x == -2 || diff_x == 2) && (diff_y == 2)){
                                        is_kill = kill(checker_board, source_x, source_y, diff_x, diff_y, '2');
                                        if(!is_kill){
                                            cout << "Wrong move!"<<endl;
                                            break;
                                        }
                                        p1_checkers--;
                                        console_removeChecker(checker_board, source_x, source_y);
                                        remove_checker(source_y, source_x);

                                        console_addChecker(checker_board, dest_x, dest_y,'2');
                                        add_checker(dest_y, dest_x, '2');
                                        //system("cls");
                                        //cleardevice();
                                        //draw_consoleCheckerBoard(checker_board);
                                        break;
                                    }

                                    else{
                                        cout << "Wrong move!" << endl;
                                        break;
                                    }
                                }
                                else{
                                     cout << "Wrong move!" << endl;
                                     break;
                                }
                            }
                            else{
                                cout << "Wrong move!" << endl;
                                break;
                            }

                    delay(600);
                 }

            }
            cout << endl;
            //-------
        }
        getch();
    }
}
