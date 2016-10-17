//
//  main.cpp
//  Shade
//
//  Created by jajabarr on 3/18/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "World.hpp"
#include "Gameplay.hpp"
#include "ShadeDevelop.hpp"
#include "CaveDevelop.hpp"
#include "Support.hpp"

int main() {
    
    World shade;
    World cave;
    World endWorld;
    Position playerPos;
    
    defaultWorld(shade);
    circularDevelopment(shade);
    
    caveWorld(cave);
    
    addShade(shade);
    
    
    cout << endl << endl;
    
    
    while (shade.getPlayer().getPlayerHealth() > 0) {
        
        if (!shade.getPlayer().getCavePos() &&
            shade.getPlayer().getNumVisits() < LAST_CAVE) {
       
            assignShade(shade, DEFAULT_DIFF, SHADE_DIFFICULTY, CIRC_DEVELOP);
            assignBeast(shade, CIRC_DEVELOP);
            shade.displayWorld();
            movePlayer(shade);
            playerPos = shade.getPlayer().getPlayerCoord();
            cave.setPlayer(shade.getPlayer());
            assignCave(shade);
            
                       
        } else if (shade.getPlayer().getCavePos()) {
            
            shade.deleteCave();
            cave.getPlayer().setNumVisits(shade.getPlayer().getNumVisits());
            cave.getPlayer().setPlayerName(shade.getPlayer().getPlayerName());
            cave.displayWorld();
            caveText(cave.getPlayer());
            movePlayer(cave);
            shade.getPlayer().setCave(cave.getPlayer().getCavePos());
            cave.getPlayer().setPlayerSteps(shade.getPlayer().getPlayerSteps());
            shade.getPlayer().setPlayerHealth(cave.getPlayer().getPlayerHealth());
            
            if (!shade.getPlayer().getCavePos()) {
                moveBeastsAway(shade);
            }
            
        } else {
            
            shade.endGame();
            shade.displayWorld();
            endTitle();
            movePlayer(shade);
            
        }
        
    }
    
    newScreen();
    newScreen();
    newScreen();
    cout << "       The world was consumed in shade.";
    newScreen();
    newScreen();
    
    
    
     
    return 0;
}
