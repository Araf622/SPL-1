#include "header.h"

void checkerBoard(char checker_board[][8]){
    int i, j;

    for(i=0 ; i<=7; i++){
        for(j=0; j<=7; j++){
            if((i+j)%2 == 0){
                if(i <= 2)  checker_board[i][j] = '2';    // player 2's checkers
                else if(i>=5) checker_board[i][j] = '1';           // player 1's checkers
                else checker_board[i][j] = '0';
            }
        }
    }
}
void draw_consoleCheckerBoard(char checker_board[][8]){
    int i, j, k;
    cout << endl << endl;

    cout << "\t\t\t\t";
    cout << "    ";
    for(k=0; k<8;k++)  cout << k << "   ";
    cout<<endl<<endl;

    for(i=0; i<8; i++){
        cout << "\t\t\t\t";
        cout << i << "  ";
        for(j=0; j<8; j++){
           if(checker_board[i][j] == '1') cout << "_1_|";
           else if (checker_board[i][j] == '2')   cout << "_2_|";
           else cout << "_ _|";
        }
        cout << endl;
    }
    cout << endl << endl;
}

