#ifndef SUPPORT_H
#define SUPPORT_H


#include <ncurses.h>
#include <string>

const int SHADE_COLOR_F = COLOR_BLACK;
const int SHADE_COLOR_B = COLOR_BLACK;

const int BEAST_COLOR_F = COLOR_BLACK;
const int BEAST_COLOR_B = COLOR_WHITE;

const int PLAYER_COLOR_F = COLOR_CYAN;
const int PLAYER_COLOR_B = COLOR_WHITE;

const int WIZARD_COLOR_F = COLOR_YELLOW;
const int WIZARD_COLOR_B = COLOR_WHITE;

const int BACKGROUND_C = COLOR_WHITE;


const int W_HEIGHT = 50;
const int W_WIDTH = 100;

const int DEF_OFFSET = (COLS - W_HEIGHT) / 4;

const char MOVE_UP = 'w';
const char MOVE_DOWN = 'a';
const char MOVE_LEFT = 's';
const char MOVE_RIGHT = 'd';

const int PLAYER_HP = 3;
const int PLAYER_STEP = 0;


#endif