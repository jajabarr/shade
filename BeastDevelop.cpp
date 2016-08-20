//
//  BeastDevelop.cpp
//  Shade
//
//  Created by prog on 4/27/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "BeastDevelop.hpp"

void assignBeast(World& world, int devType) {
    
    int x = 0;
    int y = 0;
    int assignments = 0;
    int moveNum = MOVE_DIFF_ONE;
    
    Object beast(BEAST);
    
    
    if (world.getPlayer().getPlayerSteps() < BEAST_DIFFICULTY_TWO) {
        
        if (!(world.getPlayer().getPlayerSteps() % SPAWN_ONE)) {
            assignments++;
        }
        
        moveNum = MOVE_DIFF_ONE;
        
    } else if (world.getPlayer().getPlayerSteps() < BEAST_DIFFICULTY_THREE) {
        
        if (!(world.getPlayer().getPlayerSteps() % SPAWN_TWO)) {
            assignments++;
        }
        
        moveNum = MOVE_DIFF_ONE;
        
    } else if (world.getPlayer().getPlayerSteps() < BEAST_DIFFICULTY_FOUR) {
        
        if (!(world.getPlayer().getPlayerSteps() % SPAWN_THREE)) {
            assignments++;
        }
        
        moveNum = MOVE_DIFF_TWO;
        
    } else if (world.getPlayer().getPlayerSteps() < BEAST_DIFFICULTY_FIVE) {
        
        if (!(world.getPlayer().getPlayerSteps() % SPAWN_FOUR)) {
            assignments++;
        }
        
        moveNum = MOVE_DIFF_TWO;
        
    } else if (world.getPlayer().getPlayerSteps() >= BEAST_DIFFICULTY_FIVE) {
        
        if (!(world.getPlayer().getPlayerSteps() % SPAWN_FIVE)) {
            assignments++;
        }
        
        moveNum = MOVE_DIFF_THREE;
        
    }
    
    while (assignments > 0) {
        
        checkBorder(world, x, y, SHADE_DIFFICULTY, devType);
        
        beast.setX(x);
        beast.setY(y);
        
        beast.setBeastID(world.getNumBeasts());
        world.addBeast();
        
        world.insert(beast, x, y);
        
        assignments--;
        
    }
    
    if (!(world.getPlayer().getPlayerSteps() % moveNum)) {
        
        moveBeasts(world);
    }
    
}

void moveBeasts(World& world) {
    
    char direction = ' ';
    Position checkPos;
    Object beasts[MAX_BEASTS];
    
    for (int i = 0; i < WORLD_SIZE_Y; i++) {
        for (int j = 0; j < WORLD_SIZE_X; j++) {
            
            if (world.peak(j, i).getType() == BEAST) {
                
                beasts[i + j] = world.peak(j,i);
                
                Object temp = world.peak(j, i);
                
                if (checkBeasts(beasts, (i + j), temp)) {
                    
                    checkPos.setX(temp.getX());
                    checkPos.setY(temp.getY());
                    
                    direction = world.getPlayer().getPlayerCoord().
                    closeDistance(checkPos);
                    
                    world.moveObject(temp, direction);
                    
                }
            }
        }
    }
}

bool checkBeasts(Object beasts[], int size, Object test) {
    
    for (int i = 0; i < size; i++) {
        
        if (test.getBeastID() == beasts[i].getBeastID()) {
            
            return false;
        }
    }
    
    return true;
    
}