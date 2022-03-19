#include "header.h"

void no_checkers(int n, char checker){
    if(!n){
        cout << endl;
        if(checker == '1') {
            cout << "\t\t\t\t\t" << "PLAYER 1 WON!!" << endl;
            exit(0);
        }
        else if(checker == '2'){
            cout << "\t\t\t\t\t" << "PLAYER 2 WON!!" << endl;
            exit(0);
        }
        cout << endl << endl << endl;
    }
}
