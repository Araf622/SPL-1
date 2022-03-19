
#include "header.h"

void get_mode_click(int click[]){
    click[0] = {-1};
    click[1] = {-1};
    int cur_x, cur_y;
    POINT cursor;

    //GetAsyncKeyState(VK_LBUTTON) = 0;
    while(1){
        if(GetAsyncKeyState(VK_LBUTTON)){
            GetCursorPos(&cursor);
            if(cursor.y != click[0] && cursor.x != click[1]){
                click[0] = cursor.y;
                click[1] = cursor.x;
                  break;
            }
        }
    }
}
