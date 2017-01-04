#include <iostream>
#include <ncurses.h>
#include <string>
#include "Window.h"
#include "Support.h"
#include "Object.h"
#include "World.h"
#include "Position.h"

using namespace std;

int main() {

	World shade;

	
	while (shade.is_live()) {

		shade.update();	
	}
	
	
	return 0;
}