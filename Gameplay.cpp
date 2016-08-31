//
//  Gameplay.cpp
//  Shade
//
//  Created by jajabarr on 3/19/16.
//  Copyright © 2016 jajabarr. All rights reserved.
//

#include "Gameplay.hpp"

void defaultWorld(World& world) {
    
    ifstream defaultFile;
    
    defaultFile.open(DEFAULT.c_str());
    
    if (!defaultFile.is_open()) {
        
        cout << "ERROR: DEFAULT.OPEN";
    }
    
    defaultFile >> world;
    
    defaultFile.close();
}

void caveWorld(World& world) {
    
    ifstream caveFile;
    
    caveFile.open(CAVE_FILE.c_str());
    
    if (!caveFile.is_open()) {
        
        cout << "ERROR: CAVE_FILE.OPEN";
    }
    
    caveFile >> world;
    
    caveFile.close();
}




void movePlayer(World& world) {
    
    Object worldPlayer = world.peak(world.getPlayer().getPlayerCoord().getX(),
                                    world.getPlayer().getPlayerCoord().getY());
    
    char move = ' ';
    
    cout << "Move: ";
    
    cin >> move;
    
    move = tolower(move);
    
    if (cin.fail() || !((move == MOVE_UP) || (move == MOVE_DOWN) ||
                        (move == MOVE_RIGHT) || (move == MOVE_LEFT))) {
        
        cin.clear();
        string eat;
        getline(cin, eat);
        
        cout << endl;
        cout << "Please enter a valid move!" << endl;
        
        cin >> move;
    
    }
    
    world.moveObject(worldPlayer, move);
    
    
}

void newScreen() {
    
    cout << "\n \n \n \n \n \n \n \n \n \n";
}
