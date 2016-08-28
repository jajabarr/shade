//
//  Support.hpp
//  Shade
//
//  Created by Jacob Barr on 3/18/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef Support_h
#define Support_h

#include <string>
#include <cmath>
#include "Position.hpp"
using namespace std;

class Position;

const int DEFAULT_DIFF = 1;

const int CAVE_START_X = 25;
const int CAVE_START_Y = 24;

const int WORLD_SIZE_X = 50;
const int WORLD_SIZE_Y = 25;

const int CENTER_POS_X = 25;
const int CENTER_POS_Y = 12;

const int PLAYER_MAX_HP = 3;

const int STARTING_SHADE = 360;
const int SHADE_DIFFICULTY = 100;

const int BEAST_DIFFICULTY_ONE = 100;
const int BEAST_DIFFICULTY_TWO = 300;
const int BEAST_DIFFICULTY_THREE = 500;
const int BEAST_DIFFICULTY_FOUR = 600;
const int BEAST_DIFFICULTY_FIVE = 700;

const int CAVE_SPAWN = 100;

const int SPAWN_ONE = 7;
const int SPAWN_TWO = 5;
const int SPAWN_THREE = 3;
const int SPAWN_FOUR = 2;
const int SPAWN_FIVE = 1;

const int MOVE_DIFF_ONE = 3;
const int MOVE_DIFF_TWO = 2;
const int MOVE_DIFF_THREE = 1;

const int MAX_BEASTS = WORLD_SIZE_X * WORLD_SIZE_Y;

const int NORM_DEVELOP = 1;
const int CIRC_DEVELOP = 2;

const int RAD_X = 25;
const int RAD_Y = 0;

const string SAVE_1 = "//Users//Shared//Progs//Shade//Shade//Shade//save1.txt";
const string SAVE_2 = "//Users//Shared//Progs//Shade//Shade//Shade//save2.txt";
const string SAVE_3 = "//Users//Shared//Progs//Shade//Shade//Shade//save3.txt";
const string DEFAULT = "//Users//Shared//Progs//Shade//Shade//Shade//default.txt";
const string SHADE_FILE = "//Users//Shared//Progs//Shade//Shade//Shade//shade.txt";
const string CAVE_FILE = "//Users//Shared//Progs//Shade//Shade//Shade//cave.txt";

const string RAD_STRING = "rad: ";
const string RAD_POINT = "Rxy: ";

const char PLAYER = 'P';
const char WIZARD = 'W';
const char BEAST = 'B';
const char DARK = 'S';
const char CAVE = 'C';
const char EMPTY = ' ';

const char MOVE_UP = 'w';
const char MOVE_DOWN = 's';
const char MOVE_RIGHT = 'd';
const char MOVE_LEFT = 'a';

const int DIRECTIONS_CNT = 4;

int findMin(int cnt, double dists[]);


















#endif /* Support_h */
