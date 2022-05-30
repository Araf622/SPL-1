#include "header.h"

void play(char checker_board[][8]){
    int player_selector = 1;    // to identify player
    int source_x, source_y;     // from which position to select
    int dest_x, dest_y;         // to which position to go
    int is_kill;
    bool is_move;
    int p1_checkers = 12;       // no of PLAYER 1 checkers
    int p2_checkers = 12;       // no of PLAYER 2 checkers
    int click[2];
    bool check_move;
    bool check_king_move = true;
    bool flag = false;
    bool checkNum = true;

    while(1){

        while(1){
            source_x = 100, source_y =100;
            dest_x = 100, dest_y = 100;
            check_move = true;

            // ******** PLAYER 1 **********
            if(player_selector%2){
                cout << "Player 1's turn :" << endl;
                //REMOVE PLAYER 2 MENU
                setcolor(WHITE);
                rectangle(50,100, 440, 260);
                setfillstyle(SOLID_FILL, LIGHTBLUE);
                floodfill(51, 101, WHITE);

                setcolor(LIGHTBLUE);
                rectangle(50,100, 440, 260);


                // ********CHECKS WIN CONDITION (NO CHECKERS) *****
                checkNum = no_checkers(checker_board,p2_checkers, '1');
                if(checkNum == false){
                    flag = true;
                    break;
                }

                //  ********CHECKS WIN CONDITION (NO MOVE) *****
                check_move = no_move(checker_board ,'1');
                if(check_move == false){

                    // ***CHECK KING'S MOVE **///
                    check_king_move = checkKingMove(checker_board, '4');
                    if(check_king_move == false){
                        draw_consoleCheckerBoard(checker_board);
                        settextstyle(10, 4, 4);
                        setcolor(WHITE);
                        setbkcolor(BLACK);
                        outtextxy(400, 450, "PLAYER 2 WON!!");
                        getch();
                        flag = true;
                        break;
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

                        break;
                    }
                    else{
                        cout << "wrong move" << endl;
                        //printWrongMessage();
                    }

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
                    setcolor(LIGHTBLUE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "Select Desination");

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

                                    if(dest_y == 0){
                                        console_addChecker(checker_board, dest_x, dest_y, '4');
                                        add_checker(dest_y, dest_x, '4');
                                    }

                                    else{
                                        console_addChecker(checker_board, dest_x, dest_y, '1');
                                        add_checker(dest_y, dest_x, '1');
                                    }

                                    player_selector++;
                                    break;
                                }

                                // ******* PLAYER 1 KILL *********
                                else if((diff_x == -2 || diff_x == 2) && (diff_y == -2)){
                                    is_kill = kill(checker_board, source_x, source_y, diff_x, diff_y, '1');

                                    if(!is_kill){
                                        cout << "Wrong move"<<endl;
                                        printWrongMessage();
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
                                    break;
                                }

                                    else{
                                        printWrongMessage();
                                        break;
                                    }
                                }
                                else{
                                    printWrongMessage();
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
                                            break;
                                        }
                                        console_removeChecker(checker_board,source_x, source_y);
                                        remove_checker(source_y, source_x);

                                        console_addChecker(checker_board, dest_x, dest_y, '4');
                                        add_checker(dest_y, dest_x, '4');

                                        player_selector++;
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
                                        break;
                                    }

                                    console_removeChecker(checker_board,source_x, source_y);
                                    remove_checker(source_y, source_x);

                                    console_addChecker(checker_board, dest_x, dest_y, '4');
                                    add_checker(dest_y, dest_x, '4');

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
                        //delay(600);
                    }

            }

            //***** PLAYER 2 ***********
            else{
                cout << "AI's turn :" << endl;
                //remove Player 1 Menu
                setcolor(WHITE);
                rectangle(50,100, 440, 260);
                setfillstyle(SOLID_FILL, LIGHTBLUE);
                floodfill(51, 101, WHITE);

                setcolor(LIGHTBLUE);
                rectangle(50,100, 440, 260);

                // ******** CHECKS WIN CONDITION (NO CHECKERS) *****
                checkNum = no_checkers(checker_board,p1_checkers, '2');
                if(checkNum == false){
                    flag = true;
                    break;
                }

                // *******CHECKS WIN CONDITION (NO MOVE) ********
                check_move = no_move(checker_board ,'2');
                if(check_move == false){
                    check_king_move = checkKingMove(checker_board, '8');
                    if(check_king_move == false){
                        cout << "\t\t\t" << "PLAYER 1 WON!!" << endl;
                        draw_consoleCheckerBoard(checker_board);
                        settextstyle(10, 4, 4);
                        setcolor(WHITE);
                        setbkcolor(BLACK);
                        outtextxy(400, 450, "PLAYER 1 WON!!");
                        getch();
                        flag = true;
                        break;
                    }
                }

                cout << "Player 2's move: " <<endl;
                settextstyle(3, 4, 4);
                setcolor(LIGHTBLUE);
                setbkcolor(BLACK);
                outtextxy(400, 200, "Player 2's move");

                // ask for checker until right position is entered
                while(1){

                    cout << "Select checker : ";
                    settextstyle(3, 4, 3);
                    setcolor(LIGHTBLUE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "Select Checker");

                    //cin >> source_y >> source_x;    //matrix input
                    get_source_click(click);
                    source_y = find_y_position(click[0]);
                    source_x = find_x_position(click[1]);


                    //checks validity
                    if((checker_board[source_y][source_x] == '2' || checker_board[source_y][source_x] == '8') && (source_x >=0 && source_y <=7)){
                        setcolor(WHITE);
                        rectangle(50,270,440,320);
                        setfillstyle(SOLID_FILL, LIGHTBLUE);
                        floodfill(51,271,WHITE);

                        setcolor(LIGHTBLUE);
                        rectangle(50,270,440,320);
                        break;
                    }
                    else{
                        cout << "Wrong selection!" << endl;
                    }

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
                    setcolor(LIGHTBLUE);
                    setbkcolor(BLACK);
                    outtextxy(400, 250, "Select Destination");
                    //cin >> dest_y >> dest_x;

                    get_destination_click(click);


                    dest_y = find_y_position(click[0]);
                    dest_x = find_x_position(click[1]);

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
                                    break;
                                }

                                // ******* PLAYER 2 KILL *********
                                else if((diff_x == -2 || diff_x == 2) && (diff_y == 2)){
                                    is_kill = kill(checker_board, source_x, source_y, diff_x, diff_y, '2');
                                    if(!is_kill){
                                        cout << "Wrong move!"<<endl;
                                        printWrongMessage();
                                        break;
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
                                    break;
                                }

                                else{
                                    cout << "Wrong move!" << endl;
                                    printWrongMessage();
                                    break;
                                }
                            }
                            else{
                                cout << "Wrong move!" << endl;
                                printWrongMessage();
                                break;
                            }
                        }

                    }

                    //      **** KING CHECKER ****
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

                    //delay(600);
                 }

            }
            system("cls");
            cout << endl;
            for(int i = 0; i <= 7; i++){
                for(int j = 0; j <= 7; j++){
                    cout << checker_board[i][j] << " ";
                }
                cout << endl;
            }
        }

        if(flag){
            break;
        }
        getch();
    }
}
