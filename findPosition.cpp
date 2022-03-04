#include "header.h"

int find_x_position(int x){
    for(int i = 0; i < 8; i++){
        if((x > i*80 + 450) && x < ((i+1)*80 + 450)){
            return i;
        }
    }
    return -1;
}

int find_y_position(int y){
    for(int i = 0; i < 8; i++){
        if((y > i*80 + 100) && y < ((i+1)*80 + 100)){
            return i;
        }
    }
    return -1;
}
