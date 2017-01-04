#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <iostream>
#include "Support.h"

using namespace std;

const int P_X = W_WIDTH / 2;
const int P_Y = W_HEIGHT / 2;


class Position {

private:

	int x;
	int y;

public:
	Position();
	Position(const int &x_coord, const int &y_coord);

	void update(const int &direction);
	void update(const char &direction);

	void set(const Position &position);
	void set(const int &x_coord, const int &y_coord);

	int get_x() const;
	int get_y() const;

	void print(ostream & os) const;

	bool operator<(const Position& other) const;
};

const Position PLAYER_DEFAULT = Position(P_X, P_Y);

ostream& operator<<(ostream& os, Position pos);

#endif