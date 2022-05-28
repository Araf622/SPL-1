
#include "header.h"

void multiplayer(char checker_board[][8]){

    cout<<"we are at multiplayer"<<endl;
    int move_selector = 0;      // to identify movement
    int player_selector = 1;    // to identify player
    int source_x, source_y;     // from which position to select
    int dest_x, dest_y;         // to which position to go
    int is_kill;
    bool is_move;
    int p1_checkers = 12;       // no of PLAYER 1 checkers
    int p2_checkers = 12;       // no of PLAYER 2 checkers
    int cur_x, cur_y;
    POINT cursor;
    int click[2];
    int AI_Source[2], AI_Destination[2];
    bool check_move = true;
    bool check_king_move = true;
    int i, j,k;
    bool flag = true;
    int loop = 0;

    cout << "Beginning " << endl;
    cout << "Initial1 player selector: " << player_selector << endl;
    while(1){
        cout << "Initial2 player selector: " << player_selector << endl;
        while(1){
            cout << "Initial" << endl;
            cout << "Initial3 player selector: " << player_selector << endl;
            cout << "Dekh halar po" << endl;
            source_x = 100, source_y =100;
            dest_x = 100, dest_y = 100;

            // ******** PLAYER 1 **********
            if(player_selector%2){
                cout << "Player 1's turn: "<< endl;
                //REMOVE PLAYER 2 MENU
                setcolor(WHITE);
                rectangle(50,100, 440, 260);
                setfillstyle(SOLID_FILL, LIGHTBLUE);
                floodfill(51, 101, WHITE);

                setcolor(LIGHTBLUE);
                rectangle(50,100, 440, 260);


                // ********CHECKS WIN CONDITION (NO CHECKERS) *****
                no_checkers(p2_checkers, '1');

                //  ********CHECKS WIN CONDITION (NO MOVE) *****
                check_move = no_move(checker_board ,'1');
                if(check_move == false){
                    // ***CHECK KING'S MOVE **///
                    check_king_move = checkKingMove(checker_board, '4');
                    if(check_king_move == false){
                        cout << "\t\t\t" << "PLAYER 2 WON!!" << endl;
                        // *** SHOW RESULT IN GRAPHICS ****
                        settextstyle(3, 4, 4);
                        setcolor(LIGHTBLUE);
                        setbkcolor(BLACK);
                        outtextxy(400, 340, "Player 2 WON!! No move");
                    }
                }

                /* SHOW PLAYER IN GRAPHICS WINDOW*/
                cout << "Player 1's move: " <<endl;
                settextstyle(3, 4, 4);
                setcolor(LIGHTBLUE);
                setbkcolor(BLACK);
                outtextxy(400, 200, "Player 1's move");

                // ask for checker until right position is entered
                while(1){
                    //  ......SELECT CHECKER .........
                    // ****INPUT IN GRAPHICS **
                    cout << "Select checker : ";
                    settextstyle(3, 4, 3);
                    setcolor(LIGHTBLUE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "Select Checker");


                    get_source_click(click);

                    source_y = find_y_position(click[0]);
                    source_x = find_x_position(click[1]);

                    if((checker_board[source_y][source_x] == '1' || checker_board[source_y][source_x] == '4') && (source_y >=0 && source_y <=7) && (source_x>=0 && source_x<=7)){
                        setcolor(WHITE);
                        rectangle(50,270,440,320);
                        setfillstyle(SOLID_FILL, LIGHTBLUE);
                        floodfill(51,271,WHITE);

                        setcolor(LIGHTBLUE);
                        rectangle(50,270,440,320);

                        move_selector++;
                        break;
                    }
                    else{
                        cout << "wrong move" << endl;
                        //printWrongMessage();
                    }

                    //delay(600);
                }
                bool quit = false;
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
                    setcolor(LIGHTBLUE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "Select Desination");
                    //cin >> dest_y >> dest_x;*/

                    get_destination_click(click);


                    dest_y = find_y_position(click[0]);
                    dest_x = find_x_position(click[1]);

                    int diff_x = dest_x - source_x;
                    int diff_y = dest_y - source_y;

                    if(checker_board[source_y][source_x] == '1'){
                        //checks if entered value is in range
                        if((dest_x>=0 && dest_x <=7) && (dest_y >= 0 && dest_y <=7)){

                        // checks if there is any checker in that postion
                            if(checker_board[dest_y][dest_x] == '0'){
                                //checks if the move is valid
                                if((diff_x == -1 || diff_x == 1) && (diff_y == -1)){
                                    //move
                                    console_removeChecker(checker_board,source_x, source_y);
                                    remove_checker(source_y, source_x);
                                    cout<<"#3............."<<endl;
                                    if(dest_y == 0){
                                        cout << "**" <<dest_y << "**" << dest_x << endl;
                                        console_addChecker(checker_board, dest_x, dest_y, '4');
                                        add_checker(dest_y, dest_x, '4');
                                        cout << "*****DRAW*******"<< endl;
                                    }

                                    else{
                                        console_addChecker(checker_board, dest_x, dest_y, '1');
                                        add_checker(dest_y, dest_x, '1');
                                        cout << "hehehehe"<< endl;
                                    }

                                    player_selector++;
                                    cout << "#1Player selector change : " << player_selector << endl;
                                    quit = true;
                                    break;
                                }

                                // ******* PLAYER 1 KILL *********
                                else if((diff_x == -2 || diff_x == 2) && (diff_y == -2)){
                                    is_kill = kill(checker_board, source_x, source_y, diff_x, diff_y, '1');

                                    if(!is_kill){
                                        cout << "Wrong move"<<endl;
                                        printWrongMessage();
                                        quit = true;
                                        break;
                                    }
                                    p2_checkers--;
                                    console_removeChecker(checker_board, source_x, source_y);
                                    remove_checker(source_y, source_x);

                                    if(dest_y == 0){
                                        console_addChecker(checker_board, dest_x, dest_y, '4');
                                        add_checker(dest_y, dest_x, '4');
                                    }

                                    else{
                                        console_addChecker(checker_board, dest_x, dest_y,'1');
                                        add_checker(dest_y, dest_x, '1');
                                    }

                                    quit = true;
                                    break;
                                }

                                    else{
                                        printWrongMessage();
                                        quit = true;
                                        break;
                                    }
                                }
                                else{
                                    cout << "NOOOO-1\n" << endl;
                                    cout << "Wrong move!" << endl;
                                    printWrongMessage();

                                    quit = true;
                                    break;
                                }
                            }

                            else{
                                cout << "Wrong move!" << endl;
                                printWrongMessage();

                            }
                        }

                        // ** KING CHECKER ***
                        else if(checker_board[source_y][source_x] == '4'){
                            if((dest_x>=0 && dest_x <=7) && (dest_y >= 0 && dest_y <=7)){

                                // ** KILL MOVE **
                                if(diff_x == 2 || diff_x == -2 || diff_y ==2 || diff_y == -2){
                                    is_kill = kingKill(checker_board, source_x, source_y, diff_x, diff_y, '4');

                                    if(!is_kill){

                                        is_move = kingMove(source_y, source_x, dest_y, dest_x, checker_board, '4');
                                        if(!is_move){
                                            cout << "Wrong move"<<endl;
                                            printWrongMessage();
                                            quit = true;
                                            break;
                                        }
                                        console_removeChecker(checker_board,source_x, source_y);
                                        remove_checker(source_y, source_x);

                                        console_addChecker(checker_board, dest_x, dest_y, '4');
                                        add_checker(dest_y, dest_x, '4');

                                        player_selector++;
                                        quit = true;
                                        break;
                                    }
                                    p2_checkers--;
                                    console_removeChecker(checker_board, source_x, source_y);
                                    remove_checker(source_y, source_x);

                                    console_addChecker(checker_board, dest_x, dest_y,'4');
                                    add_checker(dest_y, dest_x, '4');
                                }

                                // ** NORMAL KING MOVE ***
                                else{
                                    is_move = kingMove(source_y, source_x, dest_y, dest_x, checker_board, '4');

                                    if(!is_move){
                                        printWrongMessage();
                                        cout << "Wrong move"<<endl;
                                        quit = true;
                                        break;
                                    }

                                    console_removeChecker(checker_board,source_x, source_y);
                                    remove_checker(source_y, source_x);

                                    console_addChecker(checker_board, dest_x, dest_y, '4');
                                    add_checker(dest_y, dest_x, '4');

                                    player_selector++;
                                    quit = true;
                                    break;
                                }

                            }

                            else{
                                cout << "Wrong move!" << endl;
                                printWrongMessage();
                            }
                        }

                        else{
                            cout << "Wrong move!" << endl;
                            printWrongMessage();
                            quit = true;
                            break;
                        }
                        //delay(600);
                    }
                    if(quit)
                        break;
            }


            //***** PLAYER 2 ***********
            else{
                cout << "AI's turn: "<< endl;
                delay(1000);
                //remove Player 1 Menu
                setcolor(WHITE);
                rectangle(50,100, 440, 260);
                setfillstyle(SOLID_FILL, LIGHTBLUE);
                floodfill(51, 101, WHITE);

                setcolor(LIGHTBLUE);
                rectangle(50,100, 440, 260);

                // ******** CHECKS WIN CONDITION (NO CHECKERS) *****
                no_checkers(p1_checkers, '2');

                // *******CHECKS WIN CONDITION (NO MOVE) ********
                check_move = no_move(checker_board ,'2');
                if(check_move == false){
                    check_king_move = checkKingMove(checker_board, '8');
                    if(check_king_move == false){
                        cout << "\t\t\t" << "PLAYER 1 WON!!" << endl;
                        settextstyle(3, 4, 4);
                        setcolor(WHITE);
                        setbkcolor(BLACK);
                        outtextxy(400, 340, "Player 1 WON!! No move");
                    }
                }

                cout << "Player 2's move: " <<endl;
                settextstyle(3, 4, 4);
                setcolor(LIGHTBLUE);
                setbkcolor(BLACK);
                outtextxy(400, 200, "Player 2's move");

                AI_moveSelector(checker_board, AI_Source, AI_Destination);
                source_y = AI_Source[0];
                source_x = AI_Source[1];
                dest_y = AI_Destination[0];
                dest_x = AI_Destination[1];
                loop++;
                //if(loop == 2) closegraph();
                cout << "Source " << source_y << " " << source_x << endl;
                cout << "Dest " << dest_y << " " << dest_x << endl;
                int diff_x = dest_x - source_x;
                int diff_y = dest_y - source_y;


                    //  *** NORMAL CHECKER ***
                    if(checker_board[source_y][source_x] == '2'){
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

                                    if(dest_y == 7){
                                        checker_board[dest_y][dest_x] = '8';
                                        add_checker(dest_y, dest_x, '8');
                                    }
                                    player_selector++;
                                    cout << "#2Player selector change : " << player_selector << endl;
                                    break;
                                }

                                // ******* PLAYER 2 KILL *********
                                else if((diff_x == -2 || diff_x == 2) && (diff_y == 2)){
                                    is_kill = kill(checker_board, source_x, source_y, diff_x, diff_y, '2');
                                    if(!is_kill){
                                        cout << "Wrong move!"<<endl;
                                        printWrongMessage();
                                        //break;
                                    }
                                    p1_checkers--;
                                    console_removeChecker(checker_board, source_x, source_y);
                                    remove_checker(source_y, source_x);

                                    console_addChecker(checker_board, dest_x, dest_y,'2');
                                    add_checker(dest_y, dest_x, '2');

                                    if(dest_y == 7){
                                        checker_board[dest_y][dest_x] = '8';
                                        add_checker(dest_y, dest_x, '8');
                                    }
                                }

                                else{
                                    cout << "Wrong move!" << endl;
                                    printWrongMessage();
                                    //break;
                                }
                            }
                            else{
                                cout << "Wrong move!" << endl;
                                printWrongMessage();
                                //break;
                            }
                        }

                    }
                       else if( checker_board[source_y][source_x] == '8'){
                            if((dest_x>=0 && dest_x <=7) && (dest_y >= 0 && dest_y <=7)){

                                // ** KILL MOVE **
                                if(diff_x == 2 || diff_x == -2 || diff_y ==2 || diff_y == -2){
                                    is_kill = kingKill(checker_board, source_x, source_y, diff_x, diff_y, '8');

                                    if(!is_kill){
                                        is_move = kingMove(source_y, source_x, dest_y, dest_x, checker_board, '8');
                                        if(!is_move){
                                            cout << "Wrong move"<<endl;
                                            printWrongMessage();
                                            break;
                                        }
                                        console_removeChecker(checker_board,source_x, source_y);
                                        remove_checker(source_y, source_x);

                                        console_addChecker(checker_board, dest_x, dest_y, '8');
                                        add_checker(dest_y, dest_x, '8');

                                        player_selector++;
                                        break;
                                    }
                                    p1_checkers--;
                                    console_removeChecker(checker_board, source_x, source_y);
                                    remove_checker(source_y, source_x);

                                    console_addChecker(checker_board, dest_x, dest_y,'8');
                                    add_checker(dest_y, dest_x, '8');
                                }

                                else{
                                    is_move = kingMove(source_y, source_x, dest_y, dest_x, checker_board, '8');

                                    if(!is_move){
                                        cout << "Wrong move"<<endl;
                                        printWrongMessage();
                                        break;
                                    }

                                    console_removeChecker(checker_board,source_x, source_y);
                                    remove_checker(source_y, source_x);

                                    console_addChecker(checker_board, dest_x, dest_y, '8');
                                    add_checker(dest_y, dest_x, '8');

                                    player_selector++;
                                    break;
                                }
                            }

                            else{
                                cout << "Wrong move!" << endl;
                                printWrongMessage();
                            }
                    }

                    else{
                        cout << "Wrong move!" << endl;
                        printWrongMessage();
                        break;
                    }
                    break;
            }

            system("cls");
            cout << endl;
            for(int i = 0; i <= 7; i++){
                for(int j = 0; j <= 7; j++){
                    cout << checker_board[i][j] << " ";
                }
                cout << endl;
            }
            //-------
            //cout << "Player selector : " << player_selector << endl;
        }
        cout << "``````````````````````````````````````````````````PLAYER SELECTOR : " << player_selector << endl;
    }
}

