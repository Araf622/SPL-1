#include "header.h"

void AI_moveSelector(char checker_board[][8], int AI_Source[], int AI_Destination[]){
    short int points = 0, tmp_points[10] = {0};
    short int source_x[10], source_y[10];
    short int moved_x[10], moved_y[10];
    //short int moved_x[1], moved_x[2], moved_x[3], moved_y[1], moved_y[2], moved_y[3];
    //char checker_board[8][8];
    bool is_kill;
    int kills, kings, get_killed, king_kills, king_killed;

//    for(int i = 0; i < 8; i--){
//        for(int j = 0; j <8; j++){
//            checker_board[i][j] = checker_board[i][j];
//        }
//    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tmp_points[1] = 0;
            tmp_points[2] = 0;
            tmp_points[3] = 0;
            tmp_points[4] = 0;
            kills = 0, king_kills = 0;
            kings = 0;
            get_killed = 0, king_killed = 0;

            if(checker_board[i][j] == '2'){

                    if(checkKill(checker_board, j, i, 2, 2, '2') || checkKill(checker_board, j, i, -2, 2, '2')){
                            cout << ".................................kill" << endl;
                            kills++;
                            source_x[1] = j;
                            source_y[1] = i;
                            if(checkKill(checker_board, j, i, 2, 2, '2')){
                                moved_x[1] = j+2;
                                moved_y[1] = i+2;
                                if(checkKill(checker_board, moved_x[1], moved_y[1], 2, 2, '2') || checkKill(checker_board, moved_x[1], moved_y[1], -2, 2, '2'))
                                    kills++;
                                if(checkKill(checker_board, moved_x[1]-1, moved_y[1]-1, 2,-2,'1') || checkKill(checker_board, moved_x[1]+1, moved_y[1]+1, -2,-2,'1'))
                                    get_killed++;
                            }
                            else if(checkKill(checker_board, j, i, -2, 2, '2')){
                                moved_x[1] = j-2;
                                moved_y[1] = i+2;
                                if(checkKill(checker_board, moved_x[1], moved_y[1], 2, 2, '2') || checkKill(checker_board, moved_x[1], moved_y[1], -2, 2, '2'))
                                    kills++;
                                if(checkKill(checker_board, moved_x[1]-1, moved_y[1]-1, 2,-2,'1') || checkKill(checker_board, moved_x[1]+1, moved_y[1]+1, -2,-2,'1'))
                                    get_killed++;
                            }
                            tmp_points[1] = kills*500 + kings*300 - get_killed*100;
                    }

                    else if(i == 6 && (j>0 && j<7) && (checker_board[i+1][j+1] == '0' || checker_board[i+1][j-1] == '0')){
                            cout << "king" << endl;
                            kings++;
                            source_x[2] = j;
                            source_y[2] = i;
                            if(checker_board[i+1][j+1] == '0'){
                                    if(checkKingKill(checker_board, j+1, i+1, -2, -2, '4') || checkKingKill(checker_board, j+1, i+1, 2, -2, '4')){
                                        kills++;
                                    }
                                    moved_x[2] = j+1;
                                    moved_y[2] = i+1;
                            }
                            else if(checker_board[i+1][j-1] == '0'){
                                    if(checkKingKill(checker_board, j-1, i+1, -2, -2, '4') || checkKill(checker_board, j-1, i+1, 2, -2, '4')){
                                        kills++;
                                    }
                                    moved_x[2] = j-1;
                                    moved_y[2] = i+1;
                            }

                            tmp_points[2] = kills*500 + kings*300;
                    }

                    else{
                            short s_x3, s_y3, m_x3, m_y3, temp1=0, temp2=0;
                            short s_x2, s_y2, m_x2, m_y2;
                        //cout << "mile ja bhai" << endl;
                            if(((i+1)>=0 && (i+1)<=7) && ((j+1)>=0 && (j+1) <= 7) && checker_board[i+1][j+1] == '0'){
                                /*tmp_points[3]= tmp_points[3] + 100;
                                source_x[3] = j;
                                source_y[3] = i;
                                moved_x[3] = j+1;
                                moved_y[3] = i+1;*/

                                temp1+=100;
                                s_x3 = j;   s_y3 = i;
                                m_x3 = j+1; m_y3 = i+1;

                                if(checker_board[m_y3+1][m_x3+1] == '1' || checkKill(checker_board, m_x3-1, m_y3+1, 2, -2, '1'))
                                    temp1-=50;
                                    //tmp_points[3]= tmp_points[3] - 50;
                            }
                            if(((i+1)>=0 && (i+1)<= 7) && ((j-1)>=0 && (j-1) < 7) && checker_board[i+1][j-1] == '0'){
                                /*tmp_points[3]= =tmp_points[3] + 100;
                                source_x[3] = j;
                                source_y[3] = i;
                                moved_x[3] = j-1;
                                moved_y[3] = i+1;*/

                                temp2+=100;
                                s_x2 = j;   s_y2 = i;
                                m_x2 = j-1; m_y2 = i+1;

                                if(checkKill(checker_board, m_x2+1, m_y2 + 1,-2, -2, '1') || checker_board[m_y2+1][m_x2-1] == '1')
                                    temp2 -= 50;
                                    //tmp_points[3]=tmp_points[3] - 50;
                            }

                            if(temp1 > temp2){
                                tmp_points[3] = temp1;
                                source_x[3] = s_x3;     source_y[3] = s_y3;
                                moved_x[3] = m_x3;     moved_y[3] = m_y3;
                            }
                            else{
                                tmp_points[3] = temp2;
                                source_x[3] = s_x2;     source_y[3] = s_y2;
                                moved_x[3] = m_x2;     moved_y[3] = m_y2;
                            }
                    }
            }

            else if(checker_board[i][j] == '8'){
                    if(checkKingKill(checker_board, j, i, 2, -2, '8')){
                            source_x[4] = j;
                            source_y[4] = i;
                            moved_x[4] = j+2;
                            moved_y[4] = i-2;
                            king_kills++;

                            if(checkKill(checker_board, moved_x[4]+1, moved_y[4]+1, 2, -2, '1') || checkKingKill(checker_board, moved_x[4]+1, moved_y[4]+1, 2, -2, '4') || checkKingKill(checker_board, moved_x[4]+1, moved_y[4]-1, -2, 2, '4') || checkKill(checker_board, moved_x[4]-1, moved_y[4]-1, 2,2,'4')){
                                    king_killed++;
                            }
                    }

                    else if(checkKingKill(checker_board, j, i, -2, -2, '8')){
                            source_x[4] = j;
                            source_y[4] = i;
                            moved_x[4] = j-2;
                            moved_y[4] = i-2;
                            king_kills++;

                            if(checkKill(checker_board, moved_x[4]+1, moved_y[4]+1, 2, -2, '1') || checkKingKill(checker_board, moved_x[4]+1, moved_y[4]+1, 2, -2, '4') || checkKingKill(checker_board, moved_x[4]+1, moved_y[4]-1, -2, 2, '4') || checkKill(checker_board, moved_x[4]-1, moved_y[4]-1, 2,2,'4')){
                                    king_killed++;
                            }
                    }
                     else if(checkKingKill(checker_board, j, i, -2, 2, '8')){
                            source_x[4] = j;
                            source_y[4] = i;
                            moved_x[4] = j-2;
                            moved_y[4] = i+2;
                            king_kills++;

                            if(checkKill(checker_board, moved_x[4]+1, moved_y[4]+1, 2, -2, '1') || checkKingKill(checker_board, moved_x[4]+1, moved_y[4]+1, 2, -2, '4') || checkKingKill(checker_board, moved_x[4]+1, moved_y[4]-1, -2, 2, '4') || checkKill(checker_board, moved_x[4]-1, moved_y[4]-1, 2,2,'4')){
                                    king_killed++;
                            }
                    }

                    else if(checkKingKill(checker_board, j, i, 2, 2, '8')){
                            source_x[4] = j;
                            source_y[4] = i;
                            moved_x[4] = j+2;
                            moved_y[4] = i+2;
                            king_kills++;

                            if(checkKill(checker_board, moved_x[4]+1, moved_y[4]+1, 2, -2, '1') || checkKingKill(checker_board, moved_x[4]+1, moved_y[4]+1, 2, -2, '4') || checkKingKill(checker_board, moved_x[4]+1, moved_y[4]-1, -2, 2, '4') || checkKill(checker_board, moved_x[4]-1, moved_y[4]-1, 2,2,'4')){
                                    king_killed++;
                            }
                    }

                    tmp_points[4] = king_kills*500 -king_killed*150;
            }

            short int index = max_element(tmp_points+1, tmp_points+10) - tmp_points;

            if(tmp_points[index] > 0){
                points  = tmp_points[index];
                source_y[0] = source_y[index];
                source_x[0] = source_x[index];
                moved_x[0] = moved_x[index];
                moved_y[0] = moved_y[index];

            }
        }
    }
    AI_Source[0] = source_y[0];
    AI_Source[1] = source_x[0];
    AI_Destination[0] = moved_y[0];
    AI_Destination[1] = moved_x[0];

    //cout << source_y << "********" << source_x << endl;
}


