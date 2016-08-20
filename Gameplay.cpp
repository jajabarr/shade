//
//  Gameplay.cpp
//  Shade
//
//  Created by Jacob Barr on 3/19/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "Gameplay.hpp"

void defaultWorld(World& world) {
    
    ifstream defaultFile;
    
    defaultFile.open(DEFAULT);
    
    if (!defaultFile.is_open()) {
        
        cout << "ERROR";
    }
    
    defaultFile >> world;
    
    defaultFile.close();
}

void caveWorld(World& world) {
    
    ifstream caveFile;
    
    caveFile.open(CAVE_FILE);
    
    if (!caveFile.is_open()) {
        
        cout << "ERROR";
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
