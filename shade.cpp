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
    Position playerPos;
    
    
    defaultWorld(shade);
    circularDevelopment(shade);
    
    caveWorld(cave);
    
    addShade(shade);
    
    //cave.displayWorld();
    
    cout << endl << endl;
    
    
    while (shade.getPlayer().getPlayerHealth() > 0) {
        
        if (!shade.getPlayer().getCavePos()) {
       
            
            shade.displayWorld();
            movePlayer(shade);
            playerPos = shade.getPlayer().getPlayerCoord();
            cave.setPlayer(shade.getPlayer());
            assignShade(shade, DEFAULT_DIFF, SHADE_DIFFICULTY, CIRC_DEVELOP);
            assignBeast(shade, CIRC_DEVELOP);
            assignCave(shade);
            
        } else {
            
            shade.deleteCave();
            cave.getPlayer().setNumVisits(shade.getPlayer().getNumVisits());
            cave.getPlayer().setPlayerName(shade.getPlayer().getPlayerName());
            cave.displayWorld();
            caveText(cave.getPlayer());
            movePlayer(cave);
            shade.getPlayer().setCave(cave.getPlayer().getCavePos());
            cave.getPlayer().setPlayerSteps(shade.getPlayer().getPlayerSteps());
            shade.getPlayer().setPlayerHealth(cave.getPlayer().getPlayerHealth());
        }
        
    }
    
    
     
    return 0;
}
