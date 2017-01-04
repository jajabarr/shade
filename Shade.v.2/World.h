#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <map>
#include <cstdlib>
#include <iomanip>

#include "Window.h"
#include "Object.h"
#include "Position.h"
#include "Support.h"
#include "Comparison.h"

using namespace std;


class World {

private:

	map<Object*, map<Position, Object*>, Obj_compare> world;

	Window win;

	Object* player;



	Object* p_find(const Position& pos) const;

	void move_player(const char& direction);

	void move(const Position& pos, const char& direction);

public:

	World();

	~World();

	void p_delete(const Position& pos);

	void p_insert(Object* obj, const Position& pos);

	Object* operator[](const Position& pos);

	void update();

	bool is_live();

	



};


#endif