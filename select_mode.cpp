#include "header.h"

int select_mode(){
    int click[2];
    int x, y;
    int mode = 0;

    while(1){
        get_mode_click(click);
        y = click[0];
        x = click[1];

        if(x>=550 && x <= 950){
            if(y>=300 && y<=350){
                mode = 1;
                break;
            }

            else if(y>=370 && y<=420){
                mode = 2;
                break;
            }
            else if(y>=440 && y<=490){
                mode = 3;
                break;
            }
        }
    }
    closegraph();
    cout << "Mode : " << mode << endl;
    return mode;
}
