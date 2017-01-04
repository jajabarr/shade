#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
#include <cassert>
#include "Position.h"
#include "Support.h"


using namespace std;

const int PLAYER = 1;
const int BEAST = 2;
const int SHADE = 3;
const int WIZARD = 4;
const int BLANK = 5;

class Object {

private:
	Position coord;
	int type, color;
	char display_type;

public:
	Object();
	Object(Position pos, int id, char display, int color);

	virtual ~Object() {};

	void move(const char& direction);

	void updateDisplay(const char &disp);

	char get_display() const;

	Position location();
	virtual void noise() {

		cout << "Cool winds blow..." << endl;
	}

	virtual void print(ostream& os) const {

		os << type << ' ' << display_type << ' ' << color << ' ';
		os << coord << ' ';
	}

	bool operator<(const Object& other) const;

};

ostream& operator<<(ostream& os, const Object& o);

Object* factory(const int& type, 
		 		const Position& pos,
		 		const int& one = 0, const int& two = 0,
		 		const string& three = "");

Object* poly(const int& type);

#endif