#include "header.h"

void move_checkers(char checker_board[][8]){
    //initwindow(800, 800, "new");
    int x, y, flag=1;
    int start_x, start_y, final_x, final_y;
    int cur_x, cur_y;
    int player_turn = 0;
    POINT Cursor;
    int mouse_click1 = 0, mouse_click2 = 0;

    while(1){
        start_x = 0, start_y =0;
        final_x = 0, final_y= 0;
        //int player_turn = 0;
        while(flag){
            if(GetAsyncKeyState(VK_LBUTTON)){
                GetCursorPos(&Cursor);
                cur_x = Cursor.x;
                cur_y = Cursor.y;

                cout << find_x_position(cur_x) << " " << find_y_position(cur_y) << endl;
                delay(300);
            }
                if((player_turn%2) == 0){       //select which checker to move
                    if((cur_x!=start_x && cur_y!=start_y) && (find_x_position(cur_x) != -1 && find_y_position(cur_y) != 1)){
                        start_x = cur_x;
                        start_y = cur_y;

                        x = find_x_position(start_x);
                        y = find_y_position(start_y);

                        if(checker_board[x][y]){
                            cout << "Checker Board : " << checker_board[x][y] << endl;
                            remove_checker(x,y);
                            //cout << x << " " << y << endl;
                            flag = 0;         //check valid click
                            //player_turn++;
                        }
                    }
                }
                else if((player_turn%2)){        // select to which board to move
                    if((cur_x != start_x && cur_y != start_y) && (cur_x!=final_x && cur_y!=final_y) && (find_x_position(cur_x) != -1 && find_y_position(cur_y) != -1)){
                        final_x = cur_x;
                        final_y = cur_y;

                        x = find_x_position(final_x);
                        y = find_y_position(final_y);
                        if(!checker_board[x][y]){
                            add_checker(x,y);
                            //cout << x << " " << y << endl;
                            flag = 0;
                            //player_turn++;
                        }
                    }
                }
            }
            player_turn++;
            flag = 1;
        }
}

    /*while(1){
        if(GetAsyncKeyState(VK_LBUTTON)){
            GetCursorPos(&Cursor);
            cur_x = Cursor.x;
            cur_y = Cursor.y;
            //cout << cur_x << " " << cur_y << endl;
            x = find_x_position(cur_x);
            y = find_y_position(cur_y);
            cout << x << " " << y << endl;

            if(checker_board[x][y] && (cur_x != start_x && cur_y != start_y)){
                start_x = cur_x;
                start_y = cur_y;
                //cout << find_x_position(start_x) << " " << find_y_position(start_y) << endl;
                remove_checker(x, y);
                delay(100);
            }

        }*/
