#include "World.h"

World::World() {

	win.Setup();

	player = factory(PLAYER, PLAYER_DEFAULT, 3, 0, "Rogelio");

	world[player][PLAYER_DEFAULT] = player;

	win.add(PLAYER_DEFAULT, player);
}

Object* World::p_find(const Position& pos) const {

	for (auto &i : world) {

		auto it = i.second.find(pos);

		if (it != i.second.end()) {

			return it->second;
		}
	}

	return nullptr;
}

void World::move_player(const char& direction) {

	move((*world[player].begin()).first, direction);
}

void World::p_delete(const Position& pos) {

	for (auto &i : world) {

		auto it = i.second.find(pos);

		if (it != i.second.end()) {

			delete it->second;

			it->second = nullptr;

			i.second.erase(it);

			return;
		}
	}
}

void World::p_insert(Object* obj, const Position& pos) {

	p_delete(pos);

	world[obj][pos] = obj;

	win.add(pos, obj);
}

Object* World::operator[](const Position& pos) {

	return p_find(pos);
}

void World::move(const Position& pos, const char& direction) {

	Position p = pos;

	Object* temp = p_find(p);

	win.del(p, temp);

	p_delete(p);


	temp->move(direction);

	p.update(direction);

	p_insert(temp, p);

	win.add(p, temp);
}


void World::update() {

	move_player(win.get_key());

	win.Cycle();
}

bool World::is_live() {

	return (win.set_key() && !win.quit());
}

World::~World() {

	for(auto &i : world) {

		for (auto &j : i.second) {

			delete j.second;

			j.second = nullptr;

		}
	}
}

