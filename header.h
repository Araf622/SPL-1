#include<bits/stdc++.h>
#include <graphics.h>
#include<windows.h>
using namespace std;

void checkerBoard(char checker_board[][8]);
void draw_consoleCheckerBoard(char checker_board[][8]);
void play(char checker_board[][8]);
void console_removeChecker(char checker_board[][8], int source_x, int source_y);
void console_addChecker(char checker_board[][8], int x, int y, char checker);
int kill(char checker_board[][8],int source_x, int source_y, int diff_x, int diff_y, char checker);
void no_checkers(int n, char checker);
bool no_move(char checker_board[][8] ,char checker);

void draw_checkerBoard(char checker_board[][8]);
void move_checkers(char checker_board[][8]);
int find_x_position(int x);
int find_y_position(int y);
void remove_checker(int x, int y);
void add_checker(int x, int y);

