#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <map>
#include "Support.h"
#include "Position.h"
#include "Object.h"
#include "Comparison.h"

using namespace std;

class Window {

private:

	WINDOW * w_game;

	map<Object*, int, Obj_compare> color_map;

	int w_height, w_width;

	int offset_x, offset_y;

	int ch;

	int tickrate;


	void MakeWindow() const {

		initscr();
		noecho();
		cbreak();
		timeout(tickrate);
		keypad(w_game, TRUE);
		curs_set(0);

		printw(" ");
		refresh();
	}

	void MakeColors() const {

		start_color();

		init_pair(1, PLAYER_COLOR_F, PLAYER_COLOR_B); //player
		init_pair(2, BEAST_COLOR_F,  BEAST_COLOR_B);  //beast
		init_pair(3, SHADE_COLOR_F,  SHADE_COLOR_B);  //shade
		init_pair(4, WIZARD_COLOR_F, WIZARD_COLOR_B); //wizard
		init_pair(5, BACKGROUND_C,   BACKGROUND_C);   //background
		
		wbkgd(w_game, COLOR_PAIR(5)); //init backgroud

		attron(COLOR_PAIR(1));
		attron(COLOR_PAIR(2));
		attron(COLOR_PAIR(3));
		attron(COLOR_PAIR(4));
		attron(COLOR_PAIR(5));
	}

	void Close() const {

		attroff(COLOR_PAIR(1));
		attroff(COLOR_PAIR(2));
		attroff(COLOR_PAIR(3));
		attroff(COLOR_PAIR(4));
		attroff(COLOR_PAIR(5));

		delwin(w_game);
		endwin();

	}

public:

	Window() : w_height(W_HEIGHT), w_width(W_WIDTH), ch(0), tickrate(100) {

		MakeWindow();

		offset_x = (COLS - w_height) / 4;
		offset_y = (LINES - w_width) / 2;

		w_game = newwin(w_height, w_width, 0, offset_x);

		box(w_game, 0, 0);
		wrefresh(w_game);

		color_map[poly(PLAYER)] = PLAYER;
		color_map[poly(BEAST)] = BEAST;
		color_map[poly(SHADE)] = SHADE;
		color_map[poly(WIZARD)] = WIZARD;
		color_map[poly(BLANK)] = BLANK;
	}

	~Window() {

		Close();
	}

	bool set_key() {

		ch = getch();

		return true;
	}

	int get_key() {

		return ch;
	}

	bool quit() {

		return ch == 'q';
	}

	void Setup() const {

		MakeWindow();
		MakeColors();
	}

	void Update() const {

		clear();
		refresh();
	}

	void Cycle() const {

		Update();

		wclear(w_game);
		box(w_game, 0, 0);
		wrefresh(w_game);

	}

	void del(const Position& pos, Object* obj) {

		mvwdelch(w_game, pos.get_y(), pos.get_x());
		//move(pos.get_y(), pos.get_x());
		//delch();
		attroff(COLOR_PAIR(color_map[obj]));
	}

	void add(const Position& pos, Object* obj) {

		mvwaddch(w_game, pos.get_y(), pos.get_x(), obj->get_display());
		//move(pos.get_y(), pos.get_x());
		//addch(obj->get_display());
		attron(COLOR_PAIR(color_map[obj]));

		wrefresh(w_game);
	}



};






#endif