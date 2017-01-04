#include "Object.h"


Object::Object() 
	: coord(Position(0, 0)), type(0), color(1), display_type('x') {}

Object::Object(Position pos, int id, char display, int c)
	: coord(pos), type(id), color(c), display_type(display) {}


bool Object::operator<(const Object& other) const {

	if (this == &other) {return false;}

	return type < other.type;
}

void Object::move(const char& direction) {

	coord.update(direction);
}

void Object::updateDisplay(const char &disp) {

	display_type = disp;
}

char Object::get_display() const {

	return display_type;
}


//////////////////////////////////////////
//            SHADE CLASS               //
//////////////////////////////////////////

class Shade : public Object {

private:

	static const int SHADE_DMG = 99999;
	static const int SHADE_C = 2;
	static const char SHADE_D = 'S';

public:

	Shade() : Object() {}
	Shade(Position pos)
		: Object(pos, SHADE, SHADE_D, SHADE_C) {}

	virtual ~Shade() {};

	virtual void noise() {

		cout << "Shade has consumed the world." << endl;
	}

	virtual void print(ostream& os) const {

		Object::print(os);
	}
};


//////////////////////////////////////////
//            END OF SHADE CLASS        //
//////////////////////////////////////////




//////////////////////////////////////////
//            PLAYER CLASS              //
//////////////////////////////////////////

class Player : public Object {

private:

	static const int PLAYER_C = 4;
	static const char PLAYER_D = 'P';
	static const string PLAYER_N;

	int health, steps;
	string name;

public:

	Player() : Object(), health(3), steps(0), name(PLAYER_N)  {}

	Player(Position pos) 
		: Object(pos, PLAYER, PLAYER_D, PLAYER_C), 
		  health(3), steps(0), name(PLAYER_N) {}

	Player(Position pos, int hp, int s, string n) 
		: Object(pos, PLAYER, PLAYER_D, PLAYER_C), 
		  health(hp), steps(s), name(n) {}

	virtual ~Player() {};

	virtual void noise() {

		cout << "What am I doing wrong?" << endl;
	}

	virtual void print_player() {

		cout << "Name: " << name << " Health: " << health << "Steps: " << steps << endl;
	}

	virtual void print(ostream& os) const {

		Object::print(os);

		os << name << ' ' << health << ' ' << steps;
	}


};

const string Player::PLAYER_N = "Uma";

//////////////////////////////////////////
//            END OF PLAYER CLASS       //
//////////////////////////////////////////




//////////////////////////////////////////
//            BEAST CLASS               //
//////////////////////////////////////////
class Beast : public Object {
private:

	static const int BEAST_C = 3;
	static const char BEAST_D = 'B';

	int damage;
	int beast_id;

	static const string BEAST_N1;
	static const string BEAST_N2; 
	static const string BEAST_N3;
	static const string BEAST_N4;
	static const string BEAST_N5;



	
public:
	Beast() : Object(), damage(1), beast_id(0) {}

	Beast(Position pos) 
		: Object(pos, BEAST, BEAST_D, BEAST_C), damage(1), beast_id(0) {}

	Beast(Position pos, int id) 
		: Object(pos, BEAST, BEAST_D, BEAST_C), damage(1), beast_id(id) {}

	virtual ~Beast() {};

	virtual void noise() {

		cout << BEAST_N5 << endl;
	}



	virtual void print(ostream& os) const {

		Object::print(os);
 
		os << beast_id << ' ' << damage;
	}
};


const string Beast::BEAST_N1 = "hhhhssss";
const string Beast::BEAST_N2 = "hhhheeegg";
const string Beast::BEAST_N3 = "hhhheee mmmm";
const string Beast::BEAST_N4 = "hhheeeelll mmmm";
const string Beast::BEAST_N5 = "hhheelllppp mmmmeee";

//////////////////////////////////////////
//           END OF BEAST CLASS         //
//////////////////////////////////////////




//////////////////////////////////////////
//             WIZARD CLASS             //
//////////////////////////////////////////

class Wizard : public Object {

private:

	static const int WIZARD_C = 4;
	static const char WIZARD_D = 'W';

	static const string WIZARD_N1;
	static const string WIZARD_N2;
	static const string WIZARD_N3;
	static const string WIZARD_N4;
	static const string WIZARD_N5;
	static const string WIZARD_N6;
	static const string WIZARD_N7;
	static const string WIZARD_N8;

	int level;

public:

	Wizard() : Object(), level(0) {}

	Wizard(Position pos) 
		: Object(pos, WIZARD, WIZARD_D, WIZARD_C), level(0) {}

	Wizard(Position pos, int l) 
		: Object(pos, WIZARD, WIZARD_D, WIZARD_C), level(l) {}

	virtual ~Wizard() {};

	virtual void noise() {

		switch(level) {
		case 1:
			cout << WIZARD_N1 << endl;
			break;
		case 2:
			cout << WIZARD_N2 << endl;
			break;
		case 3:
			cout << WIZARD_N3 << endl;
			break;
		case 4:
			cout << WIZARD_N4 << endl;
			break;
		case 5:
			cout << WIZARD_N5 << endl;
			break;
		case 6:
			cout << WIZARD_N6 << endl;
			break;
		case 7:
			cout << WIZARD_N7 << endl;
			break;
		default:
			cout << WIZARD_N8 << endl;
			break;
		}
	}

	virtual void print(ostream& os) const {

		Object::print(os);
	}

};


const string Wizard::WIZARD_N1 = "\n Wizard: \"Leave now.\" \n \n";
const string Wizard::WIZARD_N2 = "\n Wizard: \"Look at them run. See how scared they are?\" \n \n";
const string Wizard::WIZARD_N3 = "\n Wizard: \"You look tired. Why don't you rest?\" \n \n";
const string Wizard::WIZARD_N4 = "\n Wizard: \"The shade is getting so close.\" \n \n";
const string Wizard::WIZARD_N5 = "\n Wizard: \"Are you afraid of the dark? I am.\" \n \n";
const string Wizard::WIZARD_N6 = "\n Wizard: \"Do you think they are dumb? They are just lke us.\" \n \n";
const string Wizard::WIZARD_N7 = "\n Wizard: \"Why don't you keep me company, before we depart?\" \n \n";
const string Wizard::WIZARD_N8 = "\n ...A cool wind blows. \n \n";

//////////////////////////////////////////
//           END OF WIZARD CLASS        //
//////////////////////////////////////////




//////////////////////////////////////////
//             BLANK CLASS              //
//////////////////////////////////////////

class Blank : public Object {
private:

	static const int BLANK_T = 5;
	static const int BLANK_C = 1;
	static const char BLANK_D = ' ';


public:

	Blank() : Object() {}
	Blank(Position pos) : Object(pos, BLANK_T, BLANK_D, BLANK_C) {}

	virtual ~Blank() {};

	virtual void noise() {

		cout << ' ' << endl;
	}
};


//////////////////////////////////////////
//             END OF BLANK CLASS       //
//////////////////////////////////////////


ostream& operator<<(ostream& os, const Object& o) {

	o.print(os);

	return os;
}

Object* factory(const int& type, 
		 		const Position& pos,
		 		const int& one, const int& two,
		 		const string& three) {

	switch(type) {
		case 1: 
			return new Player(pos, one, two, three);
			break;
		case 2:
			return new Beast(pos, one);
			break;
		case 3:
			return new Shade(pos);
			break;
		case 4:
			return new Wizard(pos, one);
			break;
		default:
			return new Blank(pos);
			break;
	}

	assert(false);
	exit(1);
}

Object* poly(const int& type) {

	Object* obj;

	Player p;
	Beast b;
	Shade s;
	Wizard w;
	Blank e;

	switch(type) {
		case 1: 
			obj = &p;
			return obj;
			break;
		case 2:
			obj = &b;
			return obj;
			break;
		case 3:
			obj = &s;
			return obj;
			break;
		case 4:
			obj = &w;
			return obj;
			break;
		default:
			obj = &e;
			return obj;
			break;
	}

}
