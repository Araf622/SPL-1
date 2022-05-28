#include <bits/stdc++.h>
#include <graphics.h>
#include<windows.h>
using namespace std;

//int kills = 0;

void checkerBoard(char checker_board[][8]);
void draw_consoleCheckerBoard(char checker_board[][8]);
void play(char checker_board[][8]);
void multiplayer(char checker_board[][8]);
void console_removeChecker(char checker_board[][8], int source_x, int source_y);
void console_addChecker(char checker_board[][8], int x, int y, char checker);
int kill(char checker_board[][8],int source_x, int source_y, int diff_x, int diff_y, char checker);
void no_checkers(int n, char checker);
bool no_move(char checker_board[][8] ,char checker);
void get_source_click(int click[]);
void get_destination_click(int click[]);
void start();
int select_mode();
void get_mode_click(int click[]);

void draw_checkerBoard(char checker_board[][8]);
void move_checkers(char checker_board[][8]);
int find_x_position(int x);
int find_y_position(int y);
void remove_checker(int y, int x);
void add_checker(int y, int x, char checker);
bool kingMove(int source_y, int source_x, int dest_y, int dest_x, char checker_board[][8], char checker);
int kingKill(char checker_board[][8],int source_x, int source_y, int diff_x, int diff_y, char checker);
bool checkKingMove(char checker_board[][8] ,char checker);
bool checkKill(char checker_board[][8],int source_x, int source_y, int diff_x, int diff_y, char checker);
bool checkKingKill(char checker_board[][8],int source_x, int source_y, int diff_x, int diff_y, char checker);
void printWrongMessage();
void AI_moveSelector(char checker_board[][8], int AI_Source[], int AI_Destination[]);

