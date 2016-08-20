//
//  Player.hpp
//  Shade
//
//  Created by Jacob Barr on 3/18/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include "Support.hpp"

using namespace std;


class Player {
    
private:
    
    int playerHealth;
    int playerSteps;
    string playerName;
    Position playerCoord;
    
public:
    
    Player();
    
    void printPlayer();
    
    void setPlayerHealth(int hp);
    int getPlayerHealth();
    
    void setPlayerSteps(int steps);
    int getPlayerSteps();
    
    void setPlayerName(string name);
    string getPlayerName();
    
    void setPlayerCoord(int posX, int posY);
    void setPlayerCoord(Position position);
    Position& getPlayerCoord();
    
    void addStep();
    void addHealth();
    void decreaseHealth();
    void killPlayer();
    void playerFullHealth();
    
    
    
    
    
};




#endif /* Player_hpp */
