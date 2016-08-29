//
//  CaveDevelop.cpp
//  Shade
//
//  Created by prog on 8/27/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "CaveDevelop.hpp"


void assignCave(World& world) {
    
    Position caveStart(CAVE_START_X, CAVE_START_Y);
    
    if ((world.getPlayer().getPlayerSteps() % 100) == 0) {
    
        if ((world.getPlayer().getPlayerCoord().getX() != CENTER_POS_X) ||
            (world.getPlayer().getPlayerCoord().getY() != CENTER_POS_Y)) {
        
            world.insert(CAVE, CENTER_POS_X, CENTER_POS_Y);
            world.setCaveCoord(CENTER_POS_X, CENTER_POS_Y);

        } else {
        
            world.insert(CAVE, CENTER_POS_X, CENTER_POS_Y - 1);
            world.setCaveCoord(CENTER_POS_X, CENTER_POS_Y - 1);
        }
    }
}