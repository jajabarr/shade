//
//  ShadeDevelope.cpp
//  Shade
//
//  Created by jajabarr on 3/19/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#include "ShadeDevelop.hpp"

bool checkTop(World world, int& posX, int& posY, int x, int y, int devType) {
    
    Position temp;
    
    if (devType == NORM_DEVELOP) {
        
        for (int i = x; i < WORLD_SIZE_X - x; i++) {
        
            if (world.isEmpty(i, y)) {
            
                posX = i;
                posY = y;
            
            
                return true;
            }
        
        }
        
    } else {
        
        
        for (int y = 0; y < WORLD_SIZE_Y; y++) {
            for (int x = 0; x < WORLD_SIZE_X; x++) {
                
                if (world.isEmpty(x, y)) {
                    
                    temp.setX(x);
                    temp.setY(y);
                    
                    if (checkRad(world, temp)) {
                        
                        posX = x;
                        posY = y;
                        
                        
                        return true;
                    }
                }
            }
        }
    }

    
    return false;
}

bool checkBottom(World world, int& posX, int& posY, int x, int y, int devType) {
    
    Position temp;
    
    if (devType == NORM_DEVELOP) {
        
        for (int i = x; i < WORLD_SIZE_X - x; i++) {
            
            if (world.isEmpty(i, WORLD_SIZE_Y - y - 1)) {
                
                posX = i;
                posY = WORLD_SIZE_Y - y - 1;
                
                
                return true;
            }
            
        }

    } else {
        
        for (int y = WORLD_SIZE_Y - 1; y > 0; y--) {
            for (int x = 0; x < WORLD_SIZE_X; x++) {
                
                if (world.isEmpty(x, y)) {
                    
                    temp.setX(x);
                    temp.setY(y);
                    
                    if (checkRad(world, temp)) {
                        
                        posX = x;
                        posY = y;
                        
                        
                        return true;
                    }
                }
            }
        }
    }
    
    
    return false;

    
}
bool checkLeft(World world, int& posX, int& posY, int x, int y, int devType) {
    
    Position temp;
    
    if (devType == NORM_DEVELOP) {
        
        for (int i = y; i < WORLD_SIZE_Y; i++) {
            
            if (world.isEmpty(x, i)) {
                
                posX = x;
                posY = i;
                
                
                return true;
            }
            
        }
        
    } else {
        
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            for (int y = 0; y < WORLD_SIZE_Y; y++) {
                
                if (world.isEmpty(x, y)) {
                    
                    temp.setX(x);
                    temp.setY(y);
                    
                    if (checkRad(world, temp)) {
                        
                        posX = x;
                        posY = y;
                        
                        return true;
                    }
                }
            }
        }
    }
    
    return false;

}

bool checkRight(World world, int& posX, int& posY, int x, int y, int devType) {
    
    Position temp;
    
    if (devType == NORM_DEVELOP) {
        
        for (int i = y; i < WORLD_SIZE_Y; i++) {
            
            if (world.isEmpty(WORLD_SIZE_X - x - 1, i)) {
                
                posX = WORLD_SIZE_X - x - 1;
                posY = i;
                
                
                return true;
            }
            
        }
        
    } else {
        
        for (int x = WORLD_SIZE_X - 1; x > 0; x--) {
            for (int y = 0; y < WORLD_SIZE_Y; y++) {
                
                if (world.isEmpty(x, y)) {
                    
                    temp.setX(x);
                    temp.setY(y);
                    
                    if (checkRad(world, temp)) {
                        
                        posX = x;
                        posY = y;
                        
                        
                        return true;
                    }
                }
            }
        }
    }
    
    return false;

}

void checkBorder(World& world, int& posX, int& posY, int difficulty, int devType) {
    
    int x = 0;
    int y = 0;
    
    bool assignedCoord = false;
    bool assigned1 = false;
    bool assigned2 = false;
    bool assigned3 = false;
    bool assigned4 = false;
    
    bool top = false;
    bool bottom = false;
    bool right = false;
    bool left = false;
    
    while (!assignedCoord) {
        
        if ((top = checkTop(world, posX, posY, x, y, devType)) &&
            (assigned1 = checkAssignShade(difficulty))) {
            
            assignedCoord = true;
        }
        
        if (!assignedCoord && (bottom = checkBottom(world, posX, posY, x, y, devType)) &&
                   (assigned2 = checkAssignShade(difficulty))) {
            
            assignedCoord = true;
        }
        
        if (!assignedCoord && (right = checkRight(world, posX, posY, x, y, devType)) &&
                   (assigned3 = checkAssignShade(difficulty))) {
            
            assignedCoord = true;
        }
        
        if (!assignedCoord && (left = checkLeft(world, posX, posY, x, y, devType)) &&
                   (assigned4 = checkAssignShade(difficulty))) {
            
            assignedCoord = true;
            
        }
    
       
        if (!top && !bottom && !right && !left) {
            x++;
            y++;
            
            if (devType == CIRC_DEVELOP) {
                
                world.trimRadPoint();
                
                world.setRadius(world.getRadPoint().getDistance(world.getCenter()));

            }
        }
    }
}

bool checkRad(World world, Position position) {
    
    if (position.getDistance(world.getCenter()) >
         world.getRadius()) {
        
        
        return true;
    }
    
    
    return false;
    
}

bool checkCirc(World world, int& posX, int& posY) {
    
    Position temp;
    
    for (int y = 0; y < WORLD_SIZE_Y; y++) {
        for (int x = 0; x < WORLD_SIZE_X; x++) {
            
            temp.setX(x);
            temp.setY(y);
            
            if ((temp.getDistance(world.getCenter()) >
                world.getRadius()) && world.isEmpty(x, y)) {
                
                posX = x;
                posY = y;
                
                
                return true;
            }
        }
    }
    
    return false;
    
    
}

void checkCircBorder(World& world, int& posX, int& posY, int difficulty) {
    
    bool assigned = false;
    bool available = false;
    
    for (int y = 0; (y < WORLD_SIZE_Y) && !assigned; y++) {
        for (int x = 0; (x < WORLD_SIZE_X) && !assigned; x++) {
            
            if ((available = checkCirc(world, x, y)) &&
                (assigned = checkAssignShade(difficulty))) {
                
                posX = x;
                posY = y;
                
                assigned = true;
                
            }
            
            if ((x == WORLD_SIZE_X - 1) && (y == WORLD_SIZE_Y - 1) &&
                available) {
                
                x = 0;
                y = 0;
            
            } else if (!available) {
                
                x = 0;
                y = 0;
                
                world.trimRadPoint();
                world.setRadius(world.getRadPoint().getDistance(world.getCenter()));
            }
            
        }
        
    }
    
    return;
}

bool checkAssignShade (int difficulty) {
    
    srand(rand() % rand());
    
    return (!((rand() % difficulty) % 2));
}

void assignShade(World& world, int assignments, int difficulty, int devType) {
    
    int x = 0;
    int y = 0;
    
    Object shade(DARK);
    
    while (assignments > 0) {
        
        checkBorder(world, x, y, difficulty, devType);
        
        shade.setX(x);
        shade.setY(y);
        
        world.insert(shade, x, y);
        
        assignments--;
        
    }

}

void normalDevelopment(World shade) {
    
    ofstream shadeFile;
    
    World world;
    Player player;
    
    world.deleteWorld();
    
    int assignments = (shade.getPlayer().getPlayerSteps() + STARTING_SHADE);
    
    int difficulty = SHADE_DIFFICULTY;
    
    assignShade(world, assignments, difficulty, NORM_DEVELOP);
    
    shadeFile.open(SHADE_FILE.c_str());
    
    if (!shadeFile.is_open()) {
        
        cout << "ERROR: SHADEFILE.OPEN" << endl;
        
        return;
    }
    
    shadeFile << world;
    
    shadeFile.close();
    
    return;
    
}

void circularDevelopment (World shade) {
    
    ofstream shadeFile;
    
    World world;
    Player player;
    
    world.deleteWorld();
    
    int assignments = (shade.getPlayer().getPlayerSteps() + STARTING_SHADE);
    
    int difficulty = SHADE_DIFFICULTY;
    
    assignShade(world, assignments, difficulty, CIRC_DEVELOP);
    
    shadeFile.open(SHADE_FILE.c_str());
    
    if (!shadeFile.is_open()) {
        
        cout << "ERROR: SHADEFILE.OPEN" << endl;
        
        return;
    }
    
    shadeFile << world;
    
    shadeFile.close();
    
    return;
    
}

void addShade(World& world) {
    
    ifstream inFile;
    
    inFile.open(SHADE_FILE.c_str());
    
    if (!inFile.is_open()) {
        
        cout << "ERROR: SHADEFILE.OPEN" << endl;
        
        return;
    }
    
    inFile >> world;
    
    inFile.close();
    
}


