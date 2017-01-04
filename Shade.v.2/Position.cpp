#include "Position.h"
#include "Support.h"
#include <ncurses.h>
#include <string>

Position::Position()
	:x(0), y(0) {}
Position::Position(const int &x_coord, const int &y_coord) 
	:x(x_coord), y(y_coord) {}

void Position::update(const int &direction) {

	if (direction == KEY_UP) {
		++y;

	} else if (direction == KEY_DOWN) {
		--y;

	} else if (direction == KEY_RIGHT) {
		++x;

	} else {

		--x;
	}
}

void Position::update(const char &direction) {

	if (direction == MOVE_UP) {
		++y;

	} else if (direction == MOVE_DOWN) {
		--y;

	} else if (direction == MOVE_RIGHT) {
		++x;

	} else {

		--x;
	}

}

void Position::set(const Position &position) {
	*this = position;
}

void Position::set(const int &x_coord, const int &y_coord) {

	x = x_coord;
	y = y_coord;
}

int Position::get_x() const {

	return x;
}

int Position::get_y() const {

	return y;
}

void Position::print(ostream & os) const {

	os << x << ' ' << y << ' ';
}

bool Position::operator<(const Position& other) const {

	if (this == &other) {return false;}

	if (x < other.x) {

		return true;

	} else if (y < other.y) {

		return true;
	}

	return false;
} 

ostream& operator<<(ostream& os, Position pos){

	pos.print(os);

	return os;
}