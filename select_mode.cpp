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
            if(y>=140 && y<=190){
                mode = 1;
                break;
            }

            else if(y>=210 && y<=260){
                mode = 2;
                break;
            }
        }
    }
    closegraph();
    cout << "Mode : " << mode << endl;
    return mode;
}
